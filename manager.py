import logging
import os
import re

import click

from src.creator import problem_map
from src.creator.null_creator import NullProblemCreator
from src.generator import Generator

EDITOR = "code"


def process_pids(raw: list[str]):
    pids = []
    for item in raw:
        t = item.split('-')
        if len(t) == 1:
            pids.extend(t)
        elif len(t) == 2:
            lb = int(re.search(r"\d+$", t[0]).group())
            rb = int(re.search(r"\d+$", t[1]).group())
            if rb < lb:
                raise Exception("题目区间错误")
            lpre = t[0][:-len(str(lb))]
            if lpre != t[1][:-len(str(rb))]:
                raise Exception("题目 ID 前缀不相同")
            for i in range(lb, rb + 1):
                pids.append(lpre + str(i))
        else:
            raise Exception("题目区间格式错误")
    return pids


@click.command("c", help="创建题目")
@click.argument("pids", nargs=-1, required=True)
@click.option("--source", "-s", type=click.Choice(["luogu"]), default="luogu", help="从何处获取题目")
@click.option("--spids", "-i", multiple=True, metavar="SOURCEIDS", help="获取哪些题面，支持区间，题目数量及顺序要与要创建的题目相同")
@click.option("--submitans", "-sa", "is_sa", is_flag=True, help="提交答案题")
@click.option("--nogen", "-ng", is_flag=True, help="不生成生成器模板")
@click.option("--nostd", "-ns", is_flag=True, help="不生成标程模板")
@click.option("--python", "-py", "use_python", is_flag=True, help="使用 python 生成器")
def create(pids: list[str], source: str, spids: list[str], is_sa: bool, nogen: bool, nostd: bool, use_python: bool):
    logger = logging.getLogger("创建题目")
    logger.debug(f"题目：{pids}，来源：[{source}]{spids}"
                 f"是否是提交答案题：{is_sa}，是否创建数据生成器：{not nogen}，是否创建标程：{not nostd}，"
                 f"是否使用 python 数据生成器：{use_python}")

    args = (is_sa, nogen, nostd, use_python)
    pids = process_pids(pids)
    logger.info(f"欲创建的题目 ID 为：{pids}")
    if spids:
        spids = process_pids(spids)
        logger.info(f"题目来源 ID 为：{spids}")
        if len(pids) != len(spids):
            raise Exception("题目数量不匹配")
        problems = [problem_map[source](pid, sid, *args) for (pid, sid) in zip(pids, spids)]
    else:
        problems = [NullProblemCreator(pid, pid, *args) for pid in pids]
    for problem in problems:
        if problem.exists():
            opt = input(f"题目 {problem} 已经存在了，继续(Y)还是跳过(Not Y)")
            if opt != 'Y':
                logger.info(f"跳过题目：{problem.pid}")
                continue
        problem.create()

    if len(problems) == 1:
        os.system(f"{EDITOR} {problems[0].md_path}")


@click.command("g", help="生成测试数据")
@click.argument("pids", nargs=-1)
def generate(pids: list[str]):
    logger = logging.getLogger("生成数据")
    logger.debug(f"题目：{pids}")

    pids = process_pids(pids)
    logger.info(f"欲生成数据的题目 ID 为：{pids}")
    for pid in pids:
        Generator(pid).generate()


@click.group()
@click.option("--level", "-l", type=click.Choice(["ERROR", "WARNING", "INFO", "DEBUG"]), default="INFO", help="日志级别")
def main(level: str):
    logging.basicConfig(level=level, format="[%(levelname)s] %(message)s")


if __name__ == "__main__":
    main.add_command(create)
    main.add_command(generate)
    main()
