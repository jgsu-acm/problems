from cyaron import *

CASES = 10

for t in range(1, CASES + 1):
    io = IO(f"{t}.in")
    # ==============================
    io.input_writeln(randint(1, int(3e13)))
    # ==============================
    io.close()
