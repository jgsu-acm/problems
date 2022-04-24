import re
import string
from typing import Callable

from src.problem import Problem

RE_CHINESE_CHAR = r"[\u4e00-\u9fa5]"
RE_CHINESE_PUNC = r"[\u3002\uff1b\uff0c\uff1a\u201c\u201d\uff08\uff09\u3001\uff1f\u300a\u300b]"
RE_CHINESE_CHAR_OR_PUNC = r"[\u3002\uff1b\uff0c\uff1a\u201c\u201d\uff08\uff09\u3001\uff1f\u300a\u300b]|[\u4e00-\u9fa5]"
RE_SEPARATED_FROM_CHN = r"[A-Za-z0-9$`]|!?\[.*?]\(.*?\)"

FORMAT_RULES: list[Callable[[str], str]] = [
    # 删除
    lambda s: s.rstrip(),
    lambda s: re.sub(rf"(?<={RE_CHINESE_CHAR_OR_PUNC}) (?={RE_CHINESE_CHAR_OR_PUNC})", "", s),  # 删除两汉字之间的空格
    lambda s: re.sub(rf" (?={RE_CHINESE_PUNC})", "", s),
    lambda s: re.sub(rf"(?<={RE_CHINESE_PUNC}) ", "", s),
    # 替换
    lambda s: re.sub(r"^- ", "* ", s),  # - -> *
    lambda s: s.replace('≤', "\\leq"),  # ≤ -> \leq
    lambda s: s.replace('≥', "\\geq"),  # ≥ -> \geq
    lambda s: s.replace('≠', "\\neq"),  # ≥ -> \neq
    lambda s: re.sub(r"\\le\s", lambda m: "\\leq ", s),  # \le -> \leq
    lambda s: re.sub(r"\\ge\s", lambda m: "\\geq ", s),  # \ge -> \geq
    lambda s: re.sub(r"\\ne\s", lambda m: "\\neq ", s),  # \ne -> \neq
    lambda s: re.sub(r"\d{2,}(?=\^)", lambda m: f"{{{m.group()}}}", s),  # 10^5 -> {10}^5
    lambda s: re.sub(rf"(?<={RE_CHINESE_CHAR}),(?={RE_CHINESE_CHAR})", "，", s),  # 两汉字间半角逗号 -> 全角
    lambda s: re.sub(rf"(?<={RE_CHINESE_CHAR}):$", "：", s),  # 汉字后半角冒号 -> 全角冒号
    # 增加
    lambda s: re.sub(rf"({RE_SEPARATED_FROM_CHN})({RE_CHINESE_CHAR})", lambda m: ' '.join(m.groups()), s),
    lambda s: re.sub(rf"({RE_CHINESE_CHAR})({RE_SEPARATED_FROM_CHN})", lambda m: ' '.join(m.groups()), s),  # 增加空格
    lambda s: re.sub(r"([A-Za-z0-9])\\", lambda m: f"{m.group(1)} \\", s),  # 增加公式中反斜杠前空格
]


class Formatter(Problem):
    def __init__(self, pid: str):
        super().__init__(pid)

    @staticmethod
    def __format_line(line: str):
        for rule in FORMAT_RULES:
            line = rule(line)
        return line

    def format(self):
        self._logger.info("格式化")
        lines = []
        with open(self._path_md, "r+", encoding="UTF-8") as fp:
            status = None
            for line in fp.readlines():
                line = self.__format_line(line)
                if status:
                    if status == "code" and line == "```":
                        status = None
                        lines[-1] += "\n```"
                    elif status == "environment" and not line:
                        status = None
                    elif status == "html" and re.match(r"</.*>", line):
                        status = None
                        lines[-1] += '\n' + line
                    elif status == "formula" and (line.count("$$") == 1 or line.count("$") % 2):
                        status = None
                        lines[-1] += '\n' + line
                    else:
                        lines[-1] += '\n' + line
                else:
                    if re.match(r"```.*", line):
                        status = "code"
                        lines.append(line)
                    elif line and line[0] in ['>', '*', '-', *string.digits, '|']:
                        status = "environment"
                        lines.append(line)
                    elif re.match(r"<.*>", line):
                        status = "html"
                        lines.append(line)
                    elif line.count("$$") == 1 or line.count("$") % 2:
                        status = "formula"
                        lines.append(line)
                    elif line:
                        lines.append(line)

        with open(self._path_md, "w", encoding="UTF-8") as fp:
            for line in lines[:-1]:
                fp.write(f"{line}\n\n")
            fp.write(f"{lines[-1]}\n")
