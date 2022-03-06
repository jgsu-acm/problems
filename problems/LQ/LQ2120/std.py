siv = [0] * 20210511
siv[1] = 1
n = 20210509
for i in range(1, n+1):
    j = 2
    while i*j <= n:
        siv[i*j] += siv[i]
        j = j+1
print(sum(siv[1:n+1]))
