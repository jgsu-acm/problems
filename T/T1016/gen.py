import random

TESTCASES = 10

for t in range(1, TESTCASES+1):
    f = open(f"{t}.in","w",encoding="UTF-8")
    while True:
        a = random.randint(pow(10,t*1000), pow(10,10001))
        b = random.randint(pow(10,t*1000), pow(10,10001))
        if not (a%998244353==0 and b%998244353==0):
            break
    f.write(str(a)+'\n')
    f.write(str(b)+'\n')
    f.close()
