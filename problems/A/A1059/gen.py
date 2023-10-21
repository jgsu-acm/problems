from cyaron import *
from random import randint
import random

CASES = 10

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    charset = "0123456789"
    head = "1234"
    heset = "0123"
    baset = "56789"
    str1 = ""
    if _t == 1:
        s = "4" * int(1e6 -1) + "5"
        io.input_writeln(s)
    elif _t == 2:
        io.input_writeln(9)
    elif _t == 3:
        io.input_writeln(12341234)
    elif _t == 4:
        s = "9" * int(1e6 -1) + "5"
        io.input_writeln(s)
    elif _t == 5:
        s = "9" + "4" * int(1e6 - 2) + "5"
        io.input_writeln(s)
    else:
        if _t <= 7:
            n = randint(1, int(1e3))
        else:
            n = randint(1, int(1e6))
        t = randint(1, n)
        he = randint(1, t)
        str1 += random.choice(head) 
        for i in range (he - 1):
            str1 += random.choice(heset)
        for i in range(t - he):
            str1 += "4"
        str1 += random.choice(baset)
        for i in range(n - t - 1):
            str1 += random.choice(charset)
        io.input_writeln(str1)
    # ==============================
    io.close()
