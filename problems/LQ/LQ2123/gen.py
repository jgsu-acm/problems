from math import floor
from cyaron import *
from random import randint
from sympy import randprime

CASES = 10

for t in range(1, CASES + 1):
    io = IO(f"{t}.in")
    # ==============================
    if t == 1:
        n = 1
    elif t == 2:
        n = 400
    elif t == 3:
        n = 551
    else:
        if t <= 6:
            maxn = 10**8
        else:
            maxn = 10**12
        if t % 3 == 0:
            n = randprime(1, maxn)
        else:
            s = floor(sqrt(sqrt(maxn)))
            k = randint(1, s)
            n = randint(1, s*s) * k * k
    io.input_writeln(n)
    # ==============================
    io.close()
