from cyaron import *

CASES = 10

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    if _t == 10:
        n = int(5e5)
        io.input_writeln(n)
        for i in range(n):
            io.input_write(n-i)
    else: 
        n = int(5e5)
        io.input_writeln(n)
        for i in range(n):
            io.input_write(randint(1, int(1e9)+1))
    # ==============================
    io.close()
