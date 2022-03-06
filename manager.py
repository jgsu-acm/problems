import logging
import re
from itertools import repeat

import click

from src.creator import problem_map, Creator
from src.generator import Generator

EDITOR = "code"

ID_SYNTAX_HELP = """
\b
{ids} 支持以下语法：
    * P1001-P1010 代表 P1001,P1002,...,P1010
    * P1001+5 代表 P1001,P1002,...,P1005
"""


def process_ids(items: list[str]):
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
                pre, lend = re.search(r"(.+)(\d+)$", l).groups()
                start, stop = map(int, [lend, r])
                stop += start
            else:
                pre, lend, rpre, rend = map(lambda s: re.search(r"(.+)(\d+)$", s).groups(), [l, r])
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
@click.option("--source", "-s", type=click.Choice(["luogu"]), default="luogu",
              callback=lambda c, p, v: v if c.params["spids"] else None, help="从何处获取题目")
@click.option("--spids", "-i", multiple=True, metavar="SOURCEIDS", help="获取哪些题面，数量及顺序要与欲创建的题目相同")
@click.option("--submitans", "-sa", "is_sa", is_flag=True, help="提交答案题")
@click.option("--nogen", "-ng", is_flag=True, help="不生成生成器模板")
@click.option("--nostd", "-ns", is_flag=True, help="不生成标程模板")
@click.option("--python", "-py", "use_python", is_flag=True, help="使用 python 生成器")
def create(pids: list[str], source: str, spids: list[str], is_sa: bool, nogen: bool, nostd: bool, use_python: bool):
    logger = logging.getLogger("创建题目")
    logger.debug(f"题目：{pids}，来源：[{source}]{spids}"
                 f"是否是提交答案题：{is_sa}，是否创建数据生成器：{not nogen}，是否创建标程：{not nostd}，"
                 f"是否使用 python 数据生成器：{use_python}")

    pids, spids = process_ids(pids), process_ids(spids)
    logger.info(f"欲创建的题目 ID 为：{pids}；题目来源 ID 为：{spids}")
    if len(pids) != len(spids):
        raise Exception("题目数量不匹配")
    args = is_sa, nogen, nostd, use_python
    iterator = iter(zip(pids, spids if spids else repeat(None)))
    problem_map.get(source, Creator)(*next(iterator), *args).create().open()
    for item in iterator:
        problem_map.get(source, Creator)(*item, *args).create()


@click.command("g", short_help="生成测试数据", help=f"生成 PIDS 测试数据\n\n{ID_SYNTAX_HELP.format(ids='PIDS')}")
@click.argument("pids", nargs=-1, required=True)
def generate(pids: list[str]):
    logger = logging.getLogger("生成数据")
    logger.debug(f"题目：{pids}")

    pids = process_ids(pids)
    logger.info(f"欲生成数据的题目 ID 为：{pids}")
    for pid in pids:
        Generator(pid).generate()


@click.group()
@click.option("--level", "-l", type=click.Choice(["ERROR", "WARNING", "INFO", "DEBUG"]), default="INFO", help="日志级别")
def main(level: str):
    logging.basicConfig(level=level, format="[%(levelname)s] <%(name)s> %(message)s")


if __name__ == "__main__":
    main.add_command(create)
    main.add_command(generate)
    main()
