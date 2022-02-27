import logging
import os
import re
import shutil

from pathlib import Path

PATH_TMP_FOLDER = Path("temp")


class Generator:
    def __init__(self, pid: str):
        self._logger = logging.getLogger("生成器")

        self.__path = Path(f"problems/{re.match(r'[A-Z]+', pid).group()}/{pid}")
        self.__gen_cpp_path = self.__path / "gen.cpp"
        self.__gen_py_path = self.__path / "gen.py"
        self.__std_path = self.__path / "std.cpp"

    @staticmethod
    def __ensure_and_clear_temp_folder():
        if not PATH_TMP_FOLDER.exists():
            PATH_TMP_FOLDER.mkdir(parents=True)
        for file in PATH_TMP_FOLDER.iterdir():
            os.remove(file)

    @staticmethod
    def __compile(path: Path):
        if os.system(f"g++ {path} -o {PATH_TMP_FOLDER / path.stem} -O2 -std=c++17"):
            raise Exception(f"{path} 编译失败")

    def generate(self):
        self._logger.info("开始创建")

        self._logger.debug("清空临时文件夹")
        self.__ensure_and_clear_temp_folder()
        if not self.__std_path.exists():
            raise Exception("标程不存在")

        self._logger.info("编译标程")
        self.__compile(self.__std_path)

        self._logger.info("生成输入样例")
        if self.__gen_cpp_path.exists():
            self._logger.info("编译生成器")
            self.__compile(self.__gen_cpp_path)
            os.system(f"cd {PATH_TMP_FOLDER} && gen")
        elif self.__gen_py_path.exists():
            shutil.copy(self.__gen_py_path, PATH_TMP_FOLDER)
            os.system(f"cd {PATH_TMP_FOLDER} && python gen.py")
        else:
            raise Exception("生成器不存在")

        self._logger.info("生成输出样例")
        files_input = PATH_TMP_FOLDER.glob("*.in")
        for file in files_input:
            os.system(f"{PATH_TMP_FOLDER / 'std'} < {file} > {PATH_TMP_FOLDER / (file.stem + '.out')}")
            self._logger.info(f"输出样例 #{file.stem} 已生成")

        self._logger.info("开始打包测试数据")
        os.system(f"7z a -tzip {self.__path / 'testcase.zip'} {PATH_TMP_FOLDER / '*.in'} {PATH_TMP_FOLDER / '*.out'}")
