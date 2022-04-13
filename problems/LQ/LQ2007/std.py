from itertools import count


def judge(x):
    while x:
        if not (x % 10 in [0, 1, 4, 9]):
            return False
        x //= 10
    return True


cnt = 0
for i in count():
    x = i*i
    if judge(x):
        cnt += 1
        if cnt == 2020:
            print(x)
            break
