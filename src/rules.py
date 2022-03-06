import re
from typing import Callable

RE_CHINESE_CHAR_OR_PUNCT = r"[\u3002\uff1b\uff0c\uff1a\u201c\u201d\uff08\uff09\u3001\uff1f\u300a\u300b]|[\u4e00-\u9fa5]"

FORMAT_RULES: list[Callable[[str], str]] = [
    lambda s: s.strip(),
    lambda s: re.sub(r"\n{3,}", "\n\n", s),  # 删除多余换行符
    lambda s: s.replace('≤', "\\leq"),  # ≤ -> \leq
    lambda s: s.replace('≥', "\\geq"),  # ≥ -> \geq
    lambda s: re.sub(r"\\le\s", lambda m: "\\leq ", s),  # \le -> \leq
    lambda s: re.sub(r"\\ge\s", lambda m: "\\geq ", s),  # \ge -> \geq
    lambda s: re.sub(r"(\d{2,})\^", lambda m: f"{{{m.group(1)}}}^", s),  # 10^5 -> {10}^5
    lambda s: re.sub(rf"(?<={RE_CHINESE_CHAR_OR_PUNCT}) (?={RE_CHINESE_CHAR_OR_PUNCT})", "", s),  # 删除两汉字之间的空格
]
