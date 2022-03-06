import re
from typing import Callable

RE_CHINESE_CHAR = r"[\u3002\uff1b\uff0c\uff1a\u201c\u201d\uff08\uff09\u3001\uff1f\u300a\u300b]|[\u4e00-\u9fa5]"

FORMAT_RULES: list[Callable[[str], str]] = [
    lambda s: s.strip(),
    lambda s: re.sub(r"\n{3,}", "\n\n", s),  # 删除多余换行符
    lambda s: s.replace('≤', "\\leq"),  # ≤ -> \leq
    lambda s: s.replace('≥', "\\geq"),  # ≥ -> \geq
    lambda s: re.sub(r"\\le\s", lambda m: "\\leq ", s),  # \le -> \leq
    lambda s: re.sub(r"\\ge\s", lambda m: "\\geq ", s),  # \ge -> \geq
    lambda s: re.sub(r"(\d{2,})\^", lambda m: f"{{{m.group(1)}}}^", s),  # 10^5 -> {10}^5
    lambda s: re.sub(rf"(?<={RE_CHINESE_CHAR}) (?={RE_CHINESE_CHAR})", "", s),  # 删除两汉字之间的空格
    lambda s: re.sub(rf"(?<={RE_CHINESE_CHAR}),(?={RE_CHINESE_CHAR})", "，", s),  # 两汉字间半角逗号 -> 全角
    lambda s: re.sub(rf"(?<={RE_CHINESE_CHAR}):$", "：", s),  # 汉字后半角冒号 -> 全角冒号
    lambda s: re.sub(rf"([A-Za-z0-9$])({RE_CHINESE_CHAR})", lambda m: f"{m.group(1)} {m.group(2)}", s),
    lambda s: re.sub(rf"({RE_CHINESE_CHAR})([A-Za-z0-9$])", lambda m: f"{m.group(1)} {m.group(2)}", s),  # 增加汉英间空格
]
