from math import floor
from cyaron import *
import networkx as nx

CASES = 10

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    if _t == 1:
        n = 10 ** 3
        m = n-1
        t = Graph.tree(n, 0.7, 0.2)
    elif _t <= 3:
        n = 10 ** 3
        m = n-1
        t = Graph.chain(n)
    elif _t <= 5:
        n = 10 ** 4
        m = n-1
        t = Graph.tree(n, 0.7, 0.2)
    elif _t <= 7:
        n = 10 ** 4
        m = n-1
        t = Graph.chain(n)
    elif _t == 8:
        n = 10 ** 5
        m = n-1
        t = Graph.tree(n, 0.7, 0.2)
    elif _t == 9:
        n = 10 ** 5
        m = n-1
        t = Graph.chain(n)
    else:
        n = 10 ** 5
        m = n-1
        t = Graph.tree(n, 0.9)
    io.input_writeln(n, m)
    if _t == 1 or _t == 5 or _t == 8:
        ls = t.to_str(output=Edge.unweighted_edge, shuffle=True).split('\n')
        for i in range(len(ls)):
            ls[i] = list(map(int, ls[i].split()))
        g = nx.Graph()
        g.add_edges_from(ls)
        edges = nx.dfs_edges(g, 1)
        for e in edges:
            io.input_writeln(e[0], e[1])
    else:
        io.input_writeln(t.to_str(output=Edge.unweighted_edge))
    if _t == 3 or _t == 7 or _t == 9:
        for i in range(m):
            opt = i % 2
            if opt:
                io.input_writeln('C', floor(i/2) + 2)
            else:
                io.input_writeln('Q', n)
    elif _t == 10:
        for i in range(m):
            p = randint(1,100)
            if p <= 20:
                opt = 1
            else:
                opt = 0
            if opt:
                io.input_writeln('C', floor(i/2) + 2)
            else:
                io.input_writeln('Q', n)
    else:
        for i in range(m):
            if i <= m/100:
                opt = 1
            else:
                opt = randint(0, 1)
            if opt:
                io.input_writeln('C', randint(1, n))
            else:
                io.input_writeln('Q', randint(n-100, n))
    # ==============================
    io.close()
