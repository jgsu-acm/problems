from random import choices
from cyaron import *

CASES = 10

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    maxv = 10 ** 9
    n = int(1e5)
    m = int(1e5)
    r = randint(1, n)
    p = randint(1, 10 ** 9)
    t = Graph.tree(n)
    io.input_writeln(n, m, r, p)
    io.input_writeln([randint(1, maxv) for i in range(n)])
    io.input_writeln(t.to_str(shuffle=True, output=Edge.unweighted_edge))
    for i in range(m):
        opt = randint(1, 4)
        x = randint(1, n)
        y = randint(1, n)
        z = randint(1, maxv)
        if opt == 1:
            io.input_writeln(opt, x, y, z)
        elif opt == 2:
            io.input_writeln(opt, x, y)
        elif opt == 3:
            io.input_writeln(opt, x, z)
        else:
            io.input_writeln(opt, x)
    # ==============================
    io.close()
