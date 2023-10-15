from cyaron import *

CASES = 10

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    headPoint = []
    for _ in range(3):
        x = randint(-1000, 1000)
        y = randint(-1000, 1000)
        while (x, y) in headPoint:
            x = randint(-1000, 1000)
            y = randint(-1000, 1000)
        headPoint.append((x, y))
    for _ in headPoint:
        io.input_writeln(_)
    n = randint(1, 1000)
    io.input_writeln(n)
    for _ in range(n):
        x = randint(-1000, 1000)
        y = randint(-1000, 1000)
        io.input_writeln(x, y)
    # ==============================
    io.close()
