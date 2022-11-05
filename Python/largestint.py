def largestInt(a,b,c):
    intList = [a,b,c]
    intList.sort()
    return intList[-1]

print(largestInt(56,34,89))