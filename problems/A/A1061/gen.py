from cyaron import *

CASES = 10

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    MAXN = int(1e6)
    MAXM = int(1e3)
    n = randint(1, MAXN)
    m = randint(1, MAXM)
    io.input_writeln(n, m)
    for i in range(1, n+1):
        io.input_write(f"{randint(1, m)} ")
    # ==============================
    io.close()
