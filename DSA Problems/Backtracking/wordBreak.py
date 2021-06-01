def solve(words, ans, target):
    if len(target) == 0:
        print(ans)
        return

    l = len(target)

    for i in range(l):
        left = target[0: i+1]
        

        if words.count(left) > 0:
            right = target[i+1:]
            # print(left, right)
            solve(words, ans + left + " ", right )


tar = ["Iamaboy","Iamagoodandobedientboy"]
dict = [['I', "boy", "am", "a", "aboy", "Iam"],
        ['I', "boy", "am", "good", "aboy", "and", "obedient", "obe", "Iam", "dient", "ando", "a", "agood"]
       ]


for i in range(2):
    print("Case:",i+1)
    print("Target stirng is: ",tar[i])
    solve(dict[i],"", tar[i])
    print("\n")