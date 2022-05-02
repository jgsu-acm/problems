from cyaron import *

CASES = 50

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    n = 10 ** 4
    if _t == 1:
        k = n
    else:
        k = randint(1, n)
    maxx = 10 ** 5
    io.input_writeln(n, k)
    if _t == 1:
        for i in range(n):
            io.input_writeln(maxx, 1)
    elif _t == 2:
        for i in range(n):
            io.input_writeln(1, maxx)
    else:
        for i in range(n):
            io.input_writeln(randint(1, maxx), randint(1, maxx))
    # ==============================
    io.close()
