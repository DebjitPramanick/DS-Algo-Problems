
def maxSub(arr):
    csum = arr[0]
    osum = arr[0]

    ans = [0]*2

    for i in range(1,len(arr)):
        if csum>=0: csum += arr[i]
        else:csum = arr[i]
        if csum > osum: osum = csum
    
    ans[0] = osum
    csum = arr[0]
    osum = arr[0]

    for i in range(1,len(arr)):
        csum = max(arr[i], csum+arr[i], csum)
        osum = csum

    ans[1] = osum

    return ans


print(maxSub([1,2,3,4]))
print(maxSub([2,-1,2,3,4,-5]))
print(maxSub([-2,-3,-1,-4,-6]))