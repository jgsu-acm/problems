from cyaron import *
from sympy import randprime
from random import randint

CASES = 10

for t in range(1, CASES + 1):
    io = IO(f"{t}.in")
    # ==============================
    _t = 10
    io.input_writeln(_t)
    for i in range(_t):
        n, m = randint(int(5e4), int(1e5)), randint(int(5e4), int(1e5))
        if m > n:
            n, m = m, n
        p = randprime(1, int(1e5))
        io.input_writeln(n, m, p)
    # ==============================
    io.close()
