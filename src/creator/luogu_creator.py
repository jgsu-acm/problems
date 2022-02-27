import re

import requests
from more_itertools import first_true

from src.creator.creator import Creator

RE_TABLE_ALIGN = r"-(?=\040\|)"
RE_EXAMPLE_CASE_NOTICE = r"【.*(?P<a>\d).*样例.*】|【.*样例.*(?P<b>\d).*】|#+.*样例.*(?P<c>\d).*|#+.*(?P<d>\d).*样例.*"
RE_CASES_RANGE = r"【数据.*】|#+\s数据.*"
RE_EXAMPLE_INPUT_CASE = r"输入样例 #\d"

URL = "https://www.luogu.com.cn/problem/{id}?_contentOnly"
HEADERS = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.102 "
                  "Safari/537.36 "
}


class LuoguProblemCreator(Creator):
    @staticmethod
    def __process_samples(samples: list[list[str]]):
        s = ""
        for i in range(len(samples)):
            sample = samples[i]
            s += f"```input{i + 1}\n{sample[0]}\n```\n\n"
            s += f"```output{i + 1}\n{sample[1]}\n```\n\n"
        return s.strip('\n')

    @staticmethod
    def __process_hint(hint: str):
        hint = re.sub(RE_TABLE_ALIGN, ":", hint)  # 单元格居中
        hint = re.sub(RE_EXAMPLE_CASE_NOTICE, lambda m: f"【样例解释 #{first_true(m.groups())}】", hint)
        hint = re.sub(RE_CASES_RANGE, "【数据规模】", hint)
        return hint.strip('\n')

    def _get(self):
        d = requests.get(URL.format(id=self._spid), headers=HEADERS).json()["currentData"]["problem"]
        self._content["background"] = d["background"].strip('\n')
        self._content["description"] = d["description"].strip('\n')
        self._content["input_format"] = d["inputFormat"].strip('\n')
        self._content["output_format"] = d["outputFormat"].strip('\n')
        self._content["samples"] = self.__process_samples(d["samples"])
        self._content["hint"] = self.__process_hint(d["hint"])
