import logging
import os
import re
import shutil
from collections import defaultdict
from pathlib import Path

from src.rules import FORMAT_RULES

PATH_GENTP_CPP = Path("template/gen_tp.cpp")
PATH_GENTP_PY = Path("template/gen_tp.py")
PATH_STDTP = Path("template/std_tp.cpp")

EDITOR = "code"


class Creator:
    sections = {
        "background": "题目背景",
        "description": "题目描述",
        "input_format": "输入格式",
        "output_format": "输出格式",
        "samples": "输入输出样例",
        "hint": "说明/提示"
    }

    def __init__(self, pid: str, spid: str, is_sa: bool, nogen: bool, nostd: bool, use_python: bool):
        self._logger = logging.getLogger(f"题目({pid})")

        self.__pid, self._spid, self.__is_sa, self.__nogen, self.__nostd, self.__use_python = \
            pid, spid, is_sa, nogen, nostd, use_python

        self._content = defaultdict(str)
        self._content["samples"] = "```input1\n\n```\n\n```output1\n\n```"

        self.__path = Path(f"problems/{re.match(r'[A-Z]+', pid).group()}/{pid}")
        self.__md_path = self.__path / f"{self.__pid}.md"
        self.__gen_path = self.__path / ("gen.py" if use_python else "gen.cpp")
        self.__gen_tp_path = PATH_GENTP_PY if use_python else PATH_GENTP_CPP
        self.__std_path = self.__path / "std.cpp"

    def _get(self):
        pass

    def _format(self):
        for k, v in self._content.items():
            for rule in FORMAT_RULES:
                v = rule(v)
            self._content[k] = v

    def __write(self):
        psecs = []
        if self._content["background"]:
            psecs.append("background")
        if self.__is_sa:
            psecs.extend(["description", "hint"])
        else:
            psecs.extend(["description", "input_format", "output_format", "samples", "hint"])
        with open(self.__md_path, "w", encoding="UTF-8") as fp:
            if psecs:
                for sec in psecs[:-1]:
                    fp.write(f"# {self.sections[sec]}\n\n")
                    if self._content[sec]:
                        fp.write(f"{self._content[sec]}\n\n")
                fp.write(f"# {self.sections[psecs[-1]]}\n")
                if self._content[psecs[-1]]:
                    fp.write(f"\n{self._content[psecs[-1]]}\n")

    def create(self):
        if self.__md_path.exists():
            if input(f"题目 {self.__pid} 已经存在了，继续(Y)还是跳过(Not Y)") != 'Y':
                self._logger.info("跳过")
                return self
        self.__path.mkdir(parents=True, exist_ok=True)
        self._logger.info("创建题面")
        self._get()
        self._format()
        self.__write()
        if self.__is_sa:
            self._logger.info("创建配置文件")
            with open(self.__path / "config.yaml", "w", encoding="UTF-8") as fp:
                fp.write('type: submit_answer\noutputs:\n  - ["", 100]\n')
            return self
        if not self.__nogen:
            self._logger.info("创建生成器")
            shutil.copy(self.__gen_tp_path, self.__gen_path)
        if not self.__nostd:
            self._logger.info("创建标程")
            shutil.copy(PATH_STDTP, self.__std_path)
        return self

    def open(self):
        os.system(f"{EDITOR} {self.__md_path}")
        return self
