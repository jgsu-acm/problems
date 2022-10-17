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
        elif _t <= 4:
            m = int(1e9)
            n = int(1e6)
            io.input_writeln(m, n)
            fl = True
            for i in range(n):
                last = m
                m -= _t*(i+1)
                if m <= 0 and fl:
                    io.input_write(last)
                    fl = False
                else:
                    io.input_write(_t*(i+1))
        else:
            m = int(1e9)
            n = int(1e6)
            io.input_writeln(m, n)
            for i in range(n-1):
                io.input_write(1)
            io.input_write(m-n+1) 
    else:
        if _t <= 7:
            m = int(1e11)
            n = int(1e6)
            io.input_writeln(m, n)
            fl = True
            for i in range(n):
                last = m
                m -= _t*(i+1)
                if m <= 0 and fl:
                    io.input_write(last)
                    fl = False
                else:
                    io.input_write(_t*(i+1))
        elif _t == 8:
            m = int(1e15)
            n = int(1e6)
            io.input_writeln(m, n)
            for i in range(n):
                io.input_write(int(1e9))
        elif _t == 9:
            m = int(1e14)
            n = int(1e6)
            io.input_writeln(m, n)
            for i in range(n):
                io.input_write(int(1e8))
        else:
            m = int(1e13)
            n = int(1e6)
            io.input_writeln(m, n)
            for i in range(n):
                io.input_write(int(1e7))
    # ==============================
    io.close()
