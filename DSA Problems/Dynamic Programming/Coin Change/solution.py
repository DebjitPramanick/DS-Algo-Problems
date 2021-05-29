# Coin Change
import sys

def getWays(n, coins):
    dp = [[0]*(n+1) for i in range(len(coins))]
    res = sys.maxsize

    for i in range(len(coins)): dp[i][0] = 1

    for  i in range(len(coins)):
        for j in range(n+1):
            if coins[i]>j: dp[i][j] = dp[i-1][j]
            else: 
                dp[i][j] = dp[i-1][j] + dp[i][j - coins[i]]
    
    return dp[-1][-1]




print(getWays(11, [1,2,5]))

