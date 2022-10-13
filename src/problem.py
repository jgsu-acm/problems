import logging
import os
import re
from pathlib import Path


class Problem:
    editor = "code"

    def __init__(self, pid: str):
        self._pid = pid
        self._logger = logging.getLogger(f"题目 {pid}")

        self._path = Path(f"problems/{re.match(r'[A-Z]+', pid).group()}/{pid}")
        self._path_md = self._path / f"{self._pid}.md"
        self._path_gen_cpp = self._path / "gen.cpp"
        self._path_gen_py = self._path / "gen.py"
        self._path_std = self._path / "std.cpp"
        self._path_config = self._path / "config.yaml"
        self._path_ignore = self._path / ".gitignore"

    def open(self):
        os.system(f"{self.editor} {self._path_md}")
        return self

    @property
    def content(self):
        return self._path_md.read_text(encoding="UTF-8")

    @property
    def is_private(self):
        return self._path_ignore.exists()
