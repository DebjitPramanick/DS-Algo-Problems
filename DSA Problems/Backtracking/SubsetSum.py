def solve(nums, idx, set, sos, tar):

    if idx == len(nums):
        if sos == tar:
            print(set, end=".")
            print("\n")
        return

    solve(nums, idx+1, set+str(nums[idx])+" ", nums[idx]+sos, tar)
    solve(nums, idx+1, set, sos, tar)
    



nums = [10, 20, 30, 14, 40, 52, 28, 2, 6, 9, 31, 56, 47, 44, 99, 100, 11, 17, 13, 23]
target = int(input("Enter target: "))
solve(nums,0,"",0,target)