from math import factorial
i = 0

def neper():
    k = 0
    for i in range(0,100):
        k = k + 1/factorial(i)
    return k

print(neper())