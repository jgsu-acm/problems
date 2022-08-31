from cyaron import *

CASES = 10

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    n = int(1e5)
    io.input_writeln(n)
    if _t <= 2:
        t = Graph.chain(n)
    elif _t <= 5:
        t = Graph.tree(n, 0.33, 0.33)  # type: ignore
    else:
        t = Graph.tree(n, 0.33, 0.5)  # type: ignore
    io.input_writeln(t.to_str(output=Edge.unweighted_edge))
    q = int(1e5)
    io.input_writeln(q)
    for _ in range(q):
        io.input_writeln(randint(1, 2), randint(2, n))
    # ==============================
    io.close()
