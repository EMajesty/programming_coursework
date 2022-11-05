import math

def approxCos(x):
    y = (-5 * x ** 2) / (32400 + x ** 2) + 1
    return y

def approxSin(x):
    y = 4 * x * (180 - x) / (40500 - x * (180 - x))
    return y

print(approxCos(20), approxSin(20))