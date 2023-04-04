from collections import defaultdict
from random import randint

from cyaron import *
from sympy import randprime

CASES = 20


def ans(n):
    fac = defaultdict(int)
    i = 2
    while i * i <= n:
        while n % i == 0:
            n //= i
            fac[i] += 1
        i += 1
    if n != 1:
        fac[n] += 1
    mul = 1
    for x, y in fac.items():
        if y % 2:
            mul *= x
    return mul


for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    if _t <= CASES * 0.3:
        l = 1
        r = 1000
    elif _t <= CASES * 0.6:
        l = 10**7
        r = 10**8
    else:
        l = 10**11
        r = 10**12
    n: int
    p = randint(1, 10)
    if p <= 5:
        n = randprime(l, r)  # type:ignore
    else:
        while True:
            n = randint(l, r)
            if ans(n) <= r:
                break
    io.input_writeln(n)
    # ==============================
    io.close()
