import logging
import re
import shutil
from abc import ABC, abstractmethod
from pathlib import Path

PATH_GENTP_CPP = Path("template/gen_tp.cpp")
PATH_GENTP_PY = Path("template/gen_tp.py")
PATH_STDTP = Path("template/std_tp.cpp")


class Creator(ABC):
    @abstractmethod
    def _get(self):
        pass

    def __init__(self, pid: str, spid: str, is_sa: bool, nogen: bool, nostd: bool, use_python: bool):
        self._logger = logging.getLogger(f"题目({pid})")
        self.__pid = pid
        self._spid = spid
        self.__is_sa = is_sa
        self.__nogen = nogen
        self.__nostd = nostd
        self.__use_python = use_python

        self._content = {
            "background": "",
            "description": "",
            "input_format": "",
            "output_format": "",
            "samples": "",
            "hint": ""
        }
        self.__path = Path(f"problems/{re.match(r'[A-Z]+', pid).group()}/{pid}")
        self.__md_path = self.__path / f"{self.__pid}.md"
        self.__gen_path = self.__path / ("gen.py" if use_python else "gen.cpp")
        self.__gen_tp_path = PATH_GENTP_PY if use_python else PATH_GENTP_CPP
        self.__std_path = self.__path / "std.cpp"

    def __write(self):
        fp = open(self.md_path, "w", encoding="UTF-8")
        if self._content["background"]:
            fp.write("# 题目背景" + "\n\n" + self._content["background"] + "\n\n")
        fp.write("# 题目描述" + "\n\n" + self._content["description"] + "\n\n")
        if not self.__is_sa:
            fp.write("# 输入格式" + "\n\n" + self._content["input_format"] + "\n\n")
            fp.write("# 输出格式" + "\n\n" + self._content["output_format"] + "\n\n")
            fp.write("# 输入输出样例" + "\n\n" + self._content["samples"] + "\n\n")
            fp.write("# 说明/提示" + "\n\n" + self._content["hint"] + "\n")
        fp.close()

    def create(self):
        self._logger.info("开始创建")
        self._get()
        self.__path.mkdir(parents=True)
        self._logger.info("创建题面")
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

    def exists(self):
        return self.__path.exists()

    @property
    def pid(self):
        return self.__pid

    @property
    def md_path(self):
        return self.__md_path
