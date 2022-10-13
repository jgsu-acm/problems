import shutil
from collections import defaultdict
from pathlib import Path

from src.formatter import Formatter
from src.problem import Problem

PATH_GENTP_CPP = Path("template/gen_tp.cpp")
PATH_GENTP_PY = Path("template/gen_tp.py")
PATH_STDTP = Path("template/std_tp.cpp")


class Creator(Problem):
    sections = {
        "background": "题目背景",
        "description": "题目描述",
        "input_format": "输入格式",
        "output_format": "输出格式",
        "samples": "输入输出样例",
        "hint": "说明/提示"
    }

    def __init__(self, pid: str, spid: str, is_sa: bool, nogen: bool, nostd: bool, use_python: bool, private: bool):
        super().__init__(pid)

        self._spid, self.__is_sa, self.__nogen, self.__nostd, self.__private = spid, is_sa, nogen, nostd, private

        self._content = defaultdict(str)
        self._content["samples"] = "```input1\n\n```\n\n```output1\n\n```"

        self.__path_gen = self._path_gen_py if use_python else self._path_gen_cpp
        self.__path_gentp = PATH_GENTP_PY if use_python else PATH_GENTP_CPP

    def _get(self):
        pass

    def __write(self):
        psecs = []
        if self._content["background"]:
            psecs.append("background")
        if self.__is_sa:
            psecs.extend(["description", "hint"])
        else:
            psecs.extend(["description", "input_format", "output_format", "samples", "hint"])
        with open(self._path_md, "w", encoding="UTF-8") as fp:
            if psecs:
                for sec in psecs[:-1]:
                    fp.write(f"# {self.sections[sec]}\n")
                    if self._content[sec]:
                        fp.write(f"{self._content[sec]}\n")
                fp.write(f"# {self.sections[psecs[-1]]}\n")
                if self._content[psecs[-1]]:
                    fp.write(f"{self._content[psecs[-1]]}")

    def create(self):
        if self._path_md.exists():
            if input(f"题目 {self._pid} 已经存在了，继续(Y)还是跳过(Not Y)").lower() != 'y':
                self._logger.info("跳过")
                return self
        self._path.mkdir(parents=True, exist_ok=True)

        self._logger.info("创建题面")
        self._get()
        self.__write()

        Formatter(self._pid).format()

        if self.__private:
            with open(self._path_ignore, "w", encoding="UTF-8") as fp:
                fp.write("*\n!.gitignore\n")

        if self.__is_sa:
            self._logger.info("创建配置文件")
            with open(self._path_config, "w", encoding="UTF-8") as fp:
                fp.write("type: objective\nanswers:\n  '1': ["", 100]\n")
            return self

        if not self.__nogen:
            self._logger.info("创建生成器")
            shutil.copy(self.__path_gentp, self.__path_gen)

        if not self.__nostd:
            self._logger.info("创建标程")
            shutil.copy(PATH_STDTP, self._path_std)

        return self
