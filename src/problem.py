import os
import re
from pathlib import Path


class Problem:
    editor = "code"

    def __init__(self, pid: str):
        self._pid = pid

        self._path = Path(f"problems/{re.match(r'[A-Z]+', pid).group()}/{pid}")
        self._path_md = self._path / f"{self._pid}.md"
        self._path_gen_cpp = self._path / "gen.cpp"
        self._path_gen_py = self._path / "gen.py"
        self._path_std = self._path / "std.cpp"

    def open(self):
        os.system(f"{self.editor} {self._path_md}")
        return self
