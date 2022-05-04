from cyaron import *

CASES = 50

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    n = 10 ** 3
    maxw = int(5e3)
    if _t == 1:
        w = 10 ** 2
    elif _t > 40:
        w = randint(10**3, maxw)
    else:
        w = randint(1, maxw)
    maxx = 10 ** 4
    io.input_writeln(n, w)
    if _t == 1:
        for i in range(n):
            io.input_writeln(maxx, 1)
    elif _t == 2:
        for i in range(n):
            io.input_writeln(1, maxx)
    elif _t == 3:
        for i in range(n):
            io.input_writeln(1, 1)
    else:
        for i in range(n):
            io.input_writeln(randint(1, maxx), randint(1, maxx))
    # ==============================
    io.close()
