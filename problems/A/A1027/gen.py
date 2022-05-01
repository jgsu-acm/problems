from cyaron import *

CASES = 50
MAXA = int(1e7)

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    if _t == 1:
        io.input_writeln(10)
        io.input_writeln(13, 8)
        io.input_writeln(1, 3)
        io.input_writeln(9, 7)
        io.input_writeln(9, 5)
        io.input_writeln(11, 5)
        io.input_writeln(14, 19)
        io.input_writeln(16, 18)
        io.input_writeln(6, 1)
        io.input_writeln(17, 1)
    else:
        n = int(1e5)
        io.input_writeln(n)
        for i in range(n):
            io.input_writeln(randint(1, MAXA), randint(1, MAXA))
    # ==============================
    io.close()
