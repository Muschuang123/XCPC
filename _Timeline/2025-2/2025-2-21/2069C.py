mod = 998244353
tt = int(input())
while tt:
    tt -= 1

    n = int(input())
    dp = [0] * 4
    dp[0] = 1
    # 1, 2, 2, ...., 3
    # 1 是状态的开始
    # 2 可以从 1 转移而来，也可以从 2 转移而来
    # 3 只能从 2 转移而来
    for x in input().split(" "):
        x = int(x)
        if x == 2:
            dp[x] *= 2
        dp[x] += dp[x - 1]
        dp[x] %= mod

    print(dp[3])
