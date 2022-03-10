dp = [0] * 20210511
dp[1] = 1
n = 20210509
for i in range(1, n+1):
    j = 2
    while i*j <= n:
        dp[i*j] += dp[i]
        j = j+1
print(sum(dp[1:n+1]))
