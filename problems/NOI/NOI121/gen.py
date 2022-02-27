from cyaron import *

CASES = 20

for t in range(1, CASES + 1):
    io = IO(f"{t}.in")
    # ==============================
    io.input_write(randint(0,int(1e18)))
    io.input_write(randint(1,int(1e18)))
    io.input_write(randint(1,int(1e18)))
    io.input_write(randint(1,int(1e18)))
    io.input_write(randint(0,int(1e18)))
    io.input_write(randint(0,int(1e18)))
    # ==============================
    io.close()
