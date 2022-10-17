from cyaron import *

CASES = 20

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    if _t == 1:
        io.input_writeln(1)
        io.input_writeln(1)
    elif _t == 2:
        n = int(1e3)
        io.input_writeln(n)
        for i in range(n):
            io.input_write(i+1)
    elif _t == 3:
        MAX = int(1e3)
        n = MAX
        io.input_writeln(n)
        for i in range(n):
            io.input_write(randint(1, MAX))
    elif _t == 4:
        io.input_writeln(8)
        io.input_writeln("1 2 1 2 3 2 1 1")
    elif _t == 5:
        io.input_writeln(10)
        io.input_writeln("1 2 3 4 5 6 5 3 4 5")
    elif _t == 6:
        io.input_writeln(5)
        io.input_writeln("1 2 3 2 1")
    elif _t == 7:
        n = int(1e5)
        io.input_writeln(n)
        for i in range(n):
            io.input_write(i+1)
    elif _t == 8:
        n = int(1e5)
        io.input_writeln(n)
        for i in range(n):
            io.input_write(int(1e9))
    elif _t <= 15:
        n = int(1e5)
        io.input_writeln(n)
        for i in range(n):
            io.input_write(randint(1, int(1e9)))
    else:
        n = int(1e5)
        io.input_writeln(n)
        for i in range(n):
            io.input_write(randint(1, int(1e5)))
    # ==============================
    io.close()
