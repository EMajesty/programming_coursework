def largestInt(a,b,c,d,e):
    intList = [a,b,c,d,e]
    intList.sort()
    return intList[-1]

print(largestInt(56,34,89,123,1))