from cyaron import *

CASES = 10

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    n = int(2e5)
    io.input_writeln(n)
    for i in range(n):
        io.input_writeln(randint(0, n+1), randint(0, n+1))
    # ==============================
    io.close()
