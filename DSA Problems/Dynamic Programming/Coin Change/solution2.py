# Coin Change (Minimum number of coins)

def getWays(n, coins):
        min_den  = [(n+1) for i in range(0,n+1)]
        min_den[0] = 0
        for i in range(1,len(min_den)):
            min_val = min_den[i]
            
            for j in coins:
                if i-j >=0:
                    min_val = min(min_val, min_den[i-j]+1)
                                        
            min_den[i] = min_val

        if min_den[-1]>n:
            return -1
        else:
            
            return min_den[-1]




print(getWays(27, [2, 5, 10, 1]))