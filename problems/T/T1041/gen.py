from itertools import count
from random import choices
from cyaron import *

CASES = 20


def phi(x):
    res = x
    for i in count(2):
        if i*i > x:
            break
        if x % i == 0:
            res = res//i*(i-1)
            while x % i == 0:
                x //= i
    if x > 1:
        res = res//x*(x-1)
    return res


for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    if _t <= 5:
        a = randint(1, 10**9)
        p = randint(1, 10**9)
        b = randint(1, phi(p))
    elif _t <= 18:
        if _t <= 13:
            a = randint(1, 10**9)
            p = randint(1, 10**9)
        else:
            tmp = randint(1, 10)
            a = tmp ** randint(1, 8)
            p = tmp ** randint(1, 8)
        b = choice("123456789") + "".join(choices(string.digits, k=10**7-1))
    else:
        p = randint(1, 10**8)
        a = p * randint(1, 10)
        b = phi(p) ** randint(100, 200)
    io.input_writeln(a, b, p)
    # ==============================
    io.close()
