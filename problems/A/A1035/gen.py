from cyaron import *

CASES = 30

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    if _t <= 10:
        a = randint(1, 100)
        b = randint(1, 100)
        c = randint(1, 100)
        while b*b-4*a*c >= 0:
            a = randint(1, 100)
            b = randint(1, 100)
            c = randint(1, 100)
        io.input_writeln(a, b, c)
    elif _t <= 20:
        a = randint(1, 100)
        b = randint(1, 100)
        c = randint(1, 100)
        while b*b-4*a*c != 0:
            a = randint(1, 100)
            b = randint(1, 100)
            c = randint(1, 100)
        io.input_writeln(a, b, c)
    else:
        a = randint(1, 100)
        b = randint(1, 100)
        c = randint(1, 100)
        while b*b-4*a*c <= 0:
            a = randint(1, 100)
            b = randint(1, 100)
            c = randint(1, 100)
        io.input_writeln(a, b, c)
    # ==============================
    io.close()
