def integerBreak(n):
    dp = [0]*(n+1)
    
    dp[0] = 0
    dp[1] = 1
    
    for i in range(2,n+1):
        for j in range(1,i):
            dif = i - j
            dp[i] = max(dif * dp[j], (i//2)**2, dp[i], dif * j)
            if i == 5:
                print(dp[i])
    
    return dp[-1]

print(integerBreak(25))