from cyaron import *

CASES = 10

for t in range(1, CASES + 1):
    io = IO(f"{t}.in")
    # ==============================
    n = 100
    k = randint(0, int(1e12)) if t <= 5 else int(1e12)
    io.input_writeln(n, k)
    for i in range(n):
        io.input_writeln(
            *(randint(-1000 if t <= 7 else 0, 1000) for j in range(n))
        )
    # ==============================
    io.close()
