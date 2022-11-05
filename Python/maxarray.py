import random
i = 0
arr = [None] * 30

while i <= 29:
    arr[i] = random.randint(1,99)
    i += 1

print(max(arr))