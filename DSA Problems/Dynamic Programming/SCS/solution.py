# Shortest Common Supersequence

'''

a: ""
b: "GXTXAYB"

Supersequence: AGGTABGXTXAYB --> [AGGTAB + GXTXAYB]

Shortest Common Supersequence: AGGXTXAYB

'''

def SCS(A: str, B: str) -> str:
        res, i, j = "", 0, 0
        lcs = LCS(A, B)
        for c in lcs:
            while A[i] != c:
                res += A[i]
                i += 1
            while B[j] != c:
                res += B[j]
                j += 1
            res+=c; i+=1; j+=1
        return res + A[i:] + B[j:]

def LCS(A: str, B: str) -> str:
        n, m = len(A), len(B)
        dp = [["" for _ in range(m + 1)] for _ in range(n + 1)]
        for i in range(n):
            for j in range(m):
                if A[i] == B[j]:
                    dp[i + 1][j + 1] = dp[i][j] + A[i]
                else:
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1], key=len)
        return dp[-1][-1]


print(SCS("AGGTAB","GXTXAYB"))