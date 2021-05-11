def substr(k, s1, s2):
    m = len(s1) + len(s2)
    tab = [[0] * m for _ in range(m)]

    a1, a2 = '', ''
    counter = 0

    for i in range(len(s1)):

        if s1[i] != s2[i] and counter == 3:
            print( i, s1[i], s2[i], a1, a2)
            a1, a2 = '', ''
            a1 += s1[i - 1]
            a2 += s2[i - 1]
            counter = 0
        elif s1[i] != s2[i]:
            counter += 1
        else:
            a1 += s1[i]
            a2 += s2[i]

    return max(len(a1), len(a2))


print(substr(2, 'tabriz', 'torino'))
