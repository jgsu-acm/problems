from cyaron import *
import random

CASES = 10
charTable = "abcdefghijklmnopqrstuvwxyz"

def shuffle_str(s):
    str_list = list(s)
    random.shuffle(str_list)
    return "".join(str_list)

def constructTrueString(n: int):
    res = "hello"
    for _ in range(n-5):
        pos = randint(0, len(res))
        res = res[:pos] + charTable[randint(0, 25)] + res[pos:]
    return res

def constructFalseString(n: int):
    modul = randint(0, 1)
    if modul:
        baned = "helo"[randint(0, 3)]
        res = ""
        for _ in range(n):
            addChar = charTable[randint(0, 25)]
            while addChar == baned:
                addChar = charTable[randint(0, 25)]
            res += addChar
        return res
    else:
        res = shuffle_str("hello")
        baned = "helo"[randint(0, 3)]
        for _ in range(n):
            addChar = charTable[randint(0, 25)]
            while addChar == baned:
                addChar = charTable[randint(0, 25)]
            pos = randint(0, len(res))
            res = res[:pos] + addChar + res[pos:]
    return res
    

for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")
    # ==============================
    t = randint(1, 100)
    io.input_writeln(t)
    for _ in range(t):
        true = (randint(1, 3) == 1)
        if true:
            n = randint(5, 100)
            io.input_writeln(constructTrueString(n))
        else:
            n = randint(1, 100)
            io.input_writeln(constructFalseString(n))
    # ==============================
    io.close()
