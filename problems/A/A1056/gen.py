from cyaron import *

CASES = 10

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    n, m = randint(1, 101), randint(1, 101)
    while n == m:
        n, m = randint(1, 101), randint(1, 101)
    if _t == 1:
        n = m
    elif _t <= 5:
        if n > m:
            n, m = m, n
    elif n < m:
        n, m = m, n
    io.input_writeln(n, m)
    for i in range(n):
        io.input_write(randint(1, 101))
    # ==============================
    io.close()
