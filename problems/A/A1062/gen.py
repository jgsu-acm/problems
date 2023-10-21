from cyaron import *

CASES = 10

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    if _t == 1:
        n, k = 5, 0
        io.input_writeln(n, k)
        for i in range(1, n + 1):
            io.input_write(i)
    elif _t == 2 :
        n, k = 5, 1
        io.input_writeln(n, k)
        for i in range(1, n + 1):
            io.input_write(i)
    else :
        n, k = int(2e6), int(1e3)
        io.input_writeln(n, k)
        for i in range(n):
            io.input_write(randint(1, int(1e9)))
    # ==============================
    io.close()
