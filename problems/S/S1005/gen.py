from random import shuffle
from cyaron import *
import networkx as nx

CASES = 10

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    if _t == 1:
        n = m = 10 ** 3
        t = Graph.tree(n, 0.7, 0.2)
    elif _t <= 3:
        n = m = 10 ** 3
        t = Graph.chain(n)
    elif _t <= 5:
        n = m = 10 ** 4
        t = Graph.tree(n, 0.7, 0.2)
    elif _t <= 7:
        n = m = 10 ** 4
        t = Graph.chain(n)
    elif _t == 8:
        n = m = 10 ** 5
        t = Graph.tree(n, 0.7, 0.2)
    else:
        n = m = 10 ** 5
        t = Graph.chain(n)
    io.input_writeln(n, m)
    ls = t.to_str(output=Edge.unweighted_edge, shuffle=True).split('\n')
    for i in range(len(ls)):
        ls[i] = list(map(int, ls[i].split()))
    g = nx.Graph()
    g.add_edges_from(ls)
    edges = nx.dfs_edges(g, 1)
    for e in edges:
        io.input_writeln(e[0], e[1])
    for i in range(m):
        if i <= m/100:
            opt = 1
        else:
            opt = randint(0, 1)
        if opt:
            io.input_writeln('C', randint(1, n))
        else:
            p = randint(1, 100)
            if p <= 30:
                io.input_writeln('Q', randint(1, n))
            else:
                io.input_writeln('Q', randint(n-100, n))
    # ==============================
    io.close()
