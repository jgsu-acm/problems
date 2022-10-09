from cyaron import *

CASES = 10

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    if _t <= 5:
        if _t <= 2:
            m = int(1e9)
            n = int(1e3)
            io.input_writeln(m, n)
            for i in range(n):
                io.input_write(_t*(i+1))
        else:
            m = int(1e9)
            n = int(1e6)
            io.input_writeln(m, n)
            for i in range(n):
                io.input_write(_t*(i+1))
    else:
        if _t <= 7:
            m = int(1e13)
            n = int(1e6)
            io.input_writeln(m, n)
            for i in range(n):
                io.input_write(_t*(i+1)*20)
        else:
            m = int(1e18)
            n = int(1e6)
            io.input_writeln(m, n)
            for i in range(n):
                io.input_write(int(1e9)-_t)
    # ==============================
    io.close()
