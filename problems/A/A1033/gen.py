from cyaron import *

CASES = 20

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    if _t <= 10:
        n = 1000
        io.input_writeln(n)
        for i in range(n):
            io.input_write(f"{randint(1, 1000)} ")
    else:
        n = 100000
        io.input_writeln(n)
        for i in range(n):
            io.input_write(f"{randint(1, 100000)} ")
    # ==============================
    io.close()
