sum = 0
num = 2

while num < 41:
    if(num % 2) == 0:
        sum = sum + num
    print("Num: ",num)
    print("Sum: ",sum)
    num += 1

sum = 0
num = 2

for num in range(41):
    if(num % 2) == 0:
        sum = sum + num
    print("Num: ",num)
    print("Sum: ",sum)

