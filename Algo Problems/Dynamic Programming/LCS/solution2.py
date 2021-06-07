# Longest common substring

def LCS2(s1, s2):
    s1 = ' '+ s1
    s2 = ' '+ s2
    tab = [[0]*len(s2) for i in range(len(s1))]
    res = 0

    for i in range(1, len(s1)):
        for j in range(1, len(s2)):
            if s1[i] == s2[j]:
                tab[i][j] = 1 + tab[i-1][j-1]
                res = max(res, tab[i][j])
            else:
                tab[i][j] = 0

    return res

print(LCS2('torino', 'tabriz'))