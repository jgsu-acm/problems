from cyaron import *

CASES = 10

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    n = 10 ** 5
    m = 10 ** 5
    io.input_writeln(n, m)
    if _t <= 5:
        t = Graph.tree(n, 0.7, 0.2)
    else:
        t = Graph.chain(n)
    io.input_writeln([randint(1, 10**6) for i in range(n)])
    io.input_writeln(t.to_str(output=Edge.unweighted_edge, shuffle=True))
    for i in range(m):
        opt = randint(1, 3)
        x = randint(1, n)
        a = randint(1, 10**6)
        if opt == 1:
            io.input_writeln(opt, x, a)
        elif opt == 2:
            io.input_writeln(opt, x, a)
        else:
            io.input_writeln(opt, x)
    # ==============================
    io.close()
