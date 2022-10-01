from cyaron import *

CASES = 10

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    io.input_writeln(randint((_t-1)*10+1, 100), randint((_t-1)*10+1, 100))
    # ==============================
    io.close()
