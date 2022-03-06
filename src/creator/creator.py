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
    def __init__(self, pid: str, spid: str, is_sa: bool, nogen: bool, nostd: bool, use_python: bool):
        self._logger = logging.getLogger(f"题目({pid})")
        self.__pid = pid
        self._spid = spid
        self.__is_sa = is_sa
        self.__nogen = nogen
        self.__nostd = nostd
        self.__use_python = use_python

        self._content = defaultdict(str)
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
        with open(self.__md_path, "w", encoding="UTF-8") as fp:
            if self._content["background"]:
                fp.write("# 题目背景" + "\n\n" + self._content["background"] + "\n\n")
            fp.write("# 题目描述" + "\n\n" + self._content["description"] + "\n\n")
            if not self.__is_sa:
                fp.write("# 输入格式" + "\n\n" + self._content["input_format"] + "\n\n")
                fp.write("# 输出格式" + "\n\n" + self._content["output_format"] + "\n\n")
                fp.write("# 输入输出样例" + "\n\n" + self._content["samples"] + "\n\n")
                fp.write("# 说明/提示" + "\n\n" + self._content["hint"] + "\n")

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
            return
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
