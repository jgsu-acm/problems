from cyaron import *

CASES = 7

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    if _t == 1:
        n, m = int(1e5), int(1e5)-1
        io.input_writeln(n, m)
        io.input_writeln(1, int(1e5))
        for i in range(m):
            io.input_writeln(i+1, i+2)
    elif _t == 2:
        n, m = int(1e5), int(1e5)-2
        io.input_writeln(n, m)
        io.input_writeln(1, int(1e5))
        for i in range(m):
            io.input_writeln(i+1, i+2)
    elif _t == 3:
        n, m = int(1e5), int(1e5)-2
        io.input_writeln(n, m)
        io.input_writeln(1, int(1e5))
        for i in range(m):
            io.input_writeln(i+2, i+3)
    elif _t == 4:
        n, m = int(1e5), int(2e5) - 4
        io.input_writeln(n, m)
        io.input_writeln(1, int(1e5))
        for i in range(m//2):
            io.input_writeln(i+1, i+2)
        for i in range(m//2):
            io.input_writeln(i+1, i+3)
    elif _t == 5:
        n, m = int(1e5), int(2e5) - 5
        io.input_writeln(n, m)
        io.input_writeln(1, int(1e5))
        for i in range(m//2):
            io.input_writeln(i+1, i+2)
        for i in range(m//2-1):
            io.input_writeln(i+1, i+3)
    elif _t == 6:
        io.input_writeln("""5 4
1 5
1 4
1 5
2 3
4 5""")
    elif _t == 7:
        io.input_writeln("""5 4
5 3
1 4
1 5
2 3
4 5""")
    # ==============================
    io.close()
