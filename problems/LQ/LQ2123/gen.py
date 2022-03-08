from cyaron import *
from random import randint

CASES = 10

for t in range(1, CASES + 1):
    io = IO(f"{t}.in")
    # ==============================
    p = randint(1, 10)
    if p <= 3:
        n = randint(1, int(1e12))
    else:
        k = randint(1, int(1e3))
        n = randint(1, int(1e6)) * k * k
    io.input_writeln(n)
    # ==============================
    io.close()
