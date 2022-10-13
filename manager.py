from dataclasses import dataclass
import logging
from os import environ
import re
from itertools import repeat
import subprocess

import click
import requests

from src.problem import Problem
from src.creator import problem_map, Creator
from src.formatter import Formatter
from src.generator import Generator

EDITOR = "code"

ID_SYNTAX_HELP = """
\b
{ids} 支持以下语法：
    * P1001-P1010 代表 P1001,P1002,...,P1010
    * P1001+5 代表 P1001,P1002,...,P1005
"""


def parse_ids(items: list[str]):
    ids = []
    for item in items:
        plus, minus = map(lambda c: item.count(c), ['+', '-'])
        if min(plus, minus) > 0 or max(plus, minus) > 1:  # 加减号不能全有，数量不能超过 1
            raise Exception("题目区间格式错误")
        if not (plus or minus):
            ids.append(item)
        else:
            l, r = item.split('+' if plus else '-')
            if plus:
                if not r.isdigit():
                    raise Exception("追加数量格式错误")
                pre, lend = re.search(r"(.+?)(\d+)$", l).groups()
                start, stop = map(int, [lend, r])
                stop += start
            else:
                (pre, lend), (rpre, rend) = map(lambda s: re.search(r"(.+)(\d+)$", s).groups(), [l, r])
                if pre != rpre:
                    raise Exception("题目 ID 前缀不相同")
                start, stop = map(int, [lend, rend])
                if start > stop:
                    raise Exception("题目区间错误")
                stop += 1
            for i in range(start, stop):
                ids.append(f"{pre}{i}")
    return ids


@click.command("c", short_help="创建题目", help=f"创建 PIDS 题目\n\n{ID_SYNTAX_HELP.format(ids='PIDS 与 SOURCEIDS')}")
@click.argument("pids", nargs=-1, required=True)
@click.option("--spids", "-i", multiple=True, metavar="SOURCEIDS", help="获取哪些题面，数量及顺序要与欲创建的题目相同")
@click.option("--source", "-s", type=click.Choice(["luogu"]), default="luogu",
              callback=lambda c, p, v: v if c.params["spids"] else None, help="从何处获取题目")
@click.option("--submitans", "-sa", "is_sa", is_flag=True, help="提交答案题")
@click.option("--nogen", "-ng", is_flag=True, help="不生成生成器模板")
@click.option("--nostd", "-ns", is_flag=True, help="不生成标程模板")
@click.option("--private", "-pr", is_flag=True, help="私有题目")
@click.option("--python", "-py", "use_python", is_flag=True, help="使用 python 生成器")
def create(pids: list[str], spids: list[str], source: str, is_sa: bool, nogen: bool, nostd: bool, use_python: bool, private: bool):
    logger = logging.getLogger(create.short_help)
    logger.debug(f"题目：{pids}，来源：[{source}]{spids}"
                 f"是否是提交答案题：{is_sa}，是否创建数据生成器：{not nogen}，是否创建标程：{not nostd}，"
                 f"是否使用 python 数据生成器：{use_python}"
                 f"是否为私有题目：{private}")

    pids, spids = parse_ids(pids), parse_ids(spids)
    logger.info(f"欲创建的题目 ID 为：{pids}")
    if spids:
        logger.info(f"题目来源 ID 为：{spids}")
        if source and len(pids) != len(spids):
            raise Exception("题目数量不匹配")
    args = is_sa, nogen, nostd, use_python, private
    iterator = iter(zip(pids, spids if spids else repeat(None)))
    problem_map.get(source, Creator)(*next(iterator), *args).create().open()
    for item in iterator:
        problem_map.get(source, Creator)(*item, *args).create()


@click.command("g", short_help="生成测试数据", help=f"生成 PIDS 测试数据\n\n{ID_SYNTAX_HELP.format(ids='PIDS')}")
@click.argument("pids", nargs=-1, required=True)
def generate(pids: list[str]):
    logger = logging.getLogger(generate.short_help)
    logger.debug(f"题目：{pids}")

    pids = parse_ids(pids)
    logger.info(f"欲生成数据的题目 ID 为：{pids}")
    for pid in pids:
        Generator(pid).generate()


@click.command("f", short_help="格式化题面", help=f"格式化 PIDS 题面\n\n{ID_SYNTAX_HELP.format(ids='PIDS')}")
@click.argument("pids", nargs=-1, required=True)
def fmt(pids: list[str]):
    logger = logging.getLogger(fmt.short_help)
    logger.debug(f"题目：{pids}")

    pids = parse_ids(pids)
    logger.info(f"欲格式化题面的题目 ID 为：{pids}")
    for pid in pids:
        Formatter(pid).format()


@click.command("cd", short_help="持续集成", help="GitHub Actions 持续集成")
def cd():
    logger = logging.getLogger(cd.short_help)

    if not ("CI" in environ.keys()):
        logger.error("非 CI 环境")
        return

    token = environ.get("TOKEN")
    if not token:
        logger.error("未设置 TOKEN")
        return

    commit_msg = subprocess.check_output(["git", "log", "-1", "--pretty=%B"]).decode().strip()

    create_re = re.compile(r"^\[\s*create:\s+(.+?)\s+([^\]]+)\]$", re.MULTILINE | re.IGNORECASE)

    problems_raw = re.findall(create_re, commit_msg)

    @dataclass
    class P:
        pid: str
        title: str
        content: str
        hidden: bool

    problems: list[P] = []

    for (index, (pid, title)) in enumerate(problems_raw):
        logger.info(f"正在创建第 {index + 1} 题：{pid} {title}")

        if not title and not pid:
            print(f"::warning ::id {index + 1} 题目 ID 和标题均不能为空")
        elif not title:
            print(f"::warning ::pid {pid} 题目标题不能为空")
        elif not pid:
            print(f"::warning ::title {title} 题目 ID 不能为空")

        problem = Problem(pid)

        content = "# Temprary Content"
        if not problem.is_private:
            content = problem.content

        problems.append(P(pid, title, content, problem.is_private))

    for problem in problems:
        payload = {
            "title": problem.title,
            "token": token,
            "pid": problem.pid,
        }
        if problem.hidden:
            payload["hidden"] = True  # type: ignore
        resp = requests.post("https://www.jgsuoj.com/rest/problem", data=payload)
        if not resp.ok:
            print(f"::error ::{problem.pid} {problem.title} 创建失败")
            continue


@click.group()
@click.option("--level", "-l", type=click.Choice(["ERROR", "WARNING", "INFO", "DEBUG"]), default="INFO", help="日志级别")
def main(level: str):
    logging.basicConfig(level=level, format="[%(levelname)s] <%(name)s> %(message)s")


if __name__ == "__main__":
    main.add_command(create)
    main.add_command(generate)
    main.add_command(fmt)
    main.add_command(cd)
    main()
