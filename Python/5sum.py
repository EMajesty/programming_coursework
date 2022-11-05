sum = 0
num = 0

while num <= 100:
    sum = sum + num
    print("Num: ",num)
    print("Sum: ",sum)
    num += 5

sum = 0
for num in range(101):
    if(num % 5) == 0:
        sum = sum + num
    print("Num: ",num)
    print("Sum: ",sum)