import random
i = 0
arr = [None] * 30
sum = 0

while i <= 29:
    arr[i] = random.randint(1,99)
    i += 1

print(arr)
i = 0
for i in range(0,len(arr)):
    sum = sum+arr[i]

print("Sum: ", str(sum))
print("Average: ", sum/30)