from cyaron import *

CASES = 10

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    if _t == 1:
        n = int(1e5)
        m = int(1e9)
        io.input_writeln(n, m)
        for i in range(n):
            io.input_write(int(1e4))
    elif _t == 2:
        n = int(1e5)
        m = int(1e5)
        io.input_writeln(n, m)
        for i in range(n):
            io.input_write(int(1e4))
    elif _t == 3:
        n = int(1e4)
        m = int(1e9)
        io.input_writeln(n, m)
        for i in range(n):
            io.input_write(int(1e4))
    elif _t == 4:
        n, m = 5, 8
        io.input_writeln(n, m)
        for i in range(n):
            io.input_write(i+1)
    elif _t == 5:
        n, m = 5, 15
        io.input_writeln(n, m)
        for i in range(n):
            io.input_write(i+1)
    elif _t == 6:
        n, m = 5, 20
        io.input_writeln(n, m)
        io.input_write(3, 7, 10, 10, 10)
    elif _t == 7:
        n, m = 7, 20
        io.input_writeln(n, m)
        io.input_write(5, 5, 5, 5, 5, 4)
    else:
        n, m = randint(1, int(1e5)), randint(1, int(1e9))
        io.input_writeln(n, m)
        for i in range(n):
            io.input_write(randint(1, int(1e4)))
    # ==============================
    io.close()
