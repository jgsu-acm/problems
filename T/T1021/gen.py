from cyaron import *

CASES = 5

for i in range(1, CASES + 1):
    io = IO(f"{i}.in")
    # ==============================
    n = int(1e4)
    m = int(5e5)
    s = randint(1, n)
    io.input_writeln(n, m, s)
    g = Graph.graph(n, m, weight_limit=1000)
    io.input_writeln(g.to_str(shuffle=True))
    # ==============================
    io.close()
