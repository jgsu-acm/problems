from cyaron import *

CASES = 10

for t in range(1, CASES + 1):
    io = IO(f"{t}.in")
    # ==============================
    q = 1000
    io.input_writeln(q)
    for i in range(q):
        io.input_writeln(randint(int(1e17), int(1e18)))
    # ==============================
    io.close()
