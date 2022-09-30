from cyaron import *

CASES = 20

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    if _t <= 3:
        n = 100
        m = randint(1, 100)
        io.input_writeln(n, m)
        for i in range(n):
            io.input_write(f"{randint(1, 100)} ")
    elif _t <= 7:
        n = 100
        m = randint(50, 90)
        io.input_writeln(n, m)
        for i in range(n):
            io.input_write(f"{randint(m, m+1)} ")
    elif _t <= 10:
        n = 100
        m = randint(1, 99)
        io.input_writeln(n, m)
        for i in range(n):
            io.input_write(f"{randint(m-1, m+1)} ")
    elif _t <= 12:
        n = 100000
        m = randint(0, 100000)
        io.input_writeln(n, m)
        for i in range(n):
            io.input_write(f"{randint(1, 100000)} ")
    elif _t <= 15:
        n = 100000
        m = randint(0, 100000)
        io.input_writeln(n, m)
        for i in range(n):
            io.input_write(f"{randint(0, 100000)} ")
    elif _t <= 17:
        n = 100000
        m = randint(88888, 99999)
        io.input_writeln(n, m)
        for i in range(n):
            io.input_write(f"{randint(m-1, m)} ")
    elif _t <= 19:
        n = 100000
        m = randint(88888, 99999)
        io.input_writeln(n, m)
        for i in range(n):
            io.input_write(f"{randint(m, m+1)} ")
    elif _t == 20:
        n = 100000
        m = 99999
        io.input_writeln(n, m)
        for i in range(n-1):
            io.input_write("99999 ")
        io.input_writeln(100000)
    # ==============================
    io.close()
