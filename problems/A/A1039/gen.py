from cyaron import *

CASES = 10
MAX = int(1e5)

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    n = m = MAX-_t+1
    io.input_writeln(n, m)
    for i in range(n):
        io.input_write(randint(1, 550))
    io.input_writeln()
    for i in range(m):
        io.input_writeln(randint(1, 10000), randint(n-10000, n), randint(1, 550))
    # ==============================
    io.close()
