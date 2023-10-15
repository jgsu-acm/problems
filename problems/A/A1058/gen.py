from cyaron import *
from random import randint
CASES = 10

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    if _t <= 8:
        io.input_writeln(randint(1, int(1e3)))
    elif _t == 9:
        io.input_writeln(int(1e5 - 1))
    else:
        io.input_writeln(int(1e5))
    # ==============================
    io.close()
