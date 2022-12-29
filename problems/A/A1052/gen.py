from cyaron import *

CASES = 20

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    n, m = int(2e5), 20-_t+1
    io.input_writeln(n, m)
    for i in range(n):
        io.input_write(randint(_t*int(1e3), _t*int(1e4)))
    # ==============================
    io.close()
