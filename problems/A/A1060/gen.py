from cyaron import *

CASES = 10

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    if _t <= 5:
        n, m = 1000, 1000
        score = 100
        io.input_writeln(n, m)
        for _ in range(n):
            io.input_write(f"{randint(0, score)} ")
        io.input_write('\n')
        for _ in range(m):
            io.input_write(f"{randint(0, score)} ")
    else:
        n, m = 100000, 100000
        score = 1000000
        io.input_writeln(n, m)
        for _ in range(n):
            io.input_write(f"{randint(0, score)} ")
        io.input_write('\n')
        for _ in range(m):
            io.input_write(f"{randint(0, score)} ")
    # ==============================
    io.close()
