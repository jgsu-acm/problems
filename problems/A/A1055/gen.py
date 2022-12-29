from cyaron import *

CASES = 4


def getWord(n, useStart=False):
    if useStart:
        start = 0
    else:
        start = n
    charset = "abcdefghijklmnopqrstuvwxyz"
    return String.random([5, 10], charset=charset[start:n*2])


for _t in range(1, CASES + 1):
    io = IO(f"{_t}.in")

    keyword_num = randint(1, 1000)
    file_length = randint(1, 1000)

    # ==============================
    io.input_writeln(f"26 {keyword_num} 1000 {file_length}")
    for i in range(26):
        # a-z
        io.input_write(chr(ord('a') + i))
        for k in range(keyword_num):
            io.input_write(getWord(_t))
        io.input_writeln()

    for i in range(1000):
        for k in range(file_length):
            io.input_write(getWord(_t, True))
        io.input_writeln()
    # ==============================
    io.close()
