
import math
def fibMod(t1,t2,n):
    for i in range(2,n):
        t1, t2 =t2, (t1 + t2**2)
    return t2

print(fibMod(1,1,20))