from cyaron import *

CASES = 10
MAXA = int(1e7)

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    n = int(1e5)
    io.input_writeln(n)
    for i in range(n):
        io.input_writeln(randint(1, MAXA), randint(1, MAXA))
    # ==============================
    io.close()
