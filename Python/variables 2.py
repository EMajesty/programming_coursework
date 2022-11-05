a = 999
b = 666
c = 333

largest = max(a,b,c)
print(largest)

if a > b and a > c:
    print(a)
elif b > a and b > c:
    print(b)
elif c > a and c > b:
    print(c)

list1 = [a,b,c]
list1.sort()
print(list1[-1])