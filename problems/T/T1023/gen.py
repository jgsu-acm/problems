from cyaron import *

CASES = 10

for i in range(1, CASES + 1):
    io = IO(f"{i}.in")
    # ==============================
    n = int(2e5)
    m = int(2e5)
    s = randint(1, n)
    io.input_writeln(n, m, s)
    if i <= 3:
        tree = Graph.tree(n)
    elif i <= 5:
        tree = Graph.tree(n, 0.9)
    elif i <= 7:
        tree = Graph.tree(n, flower=0.9)
    else:
        tree = Graph.tree(n, 0.3, 0.3)
    io.input_writeln(tree.to_str(shuffle=True, output=Edge.unweighted_edge))
    for i in range(m):
        io.input_writeln(randint(1, n), randint(1, n))
    # ==============================
    io.close()
