import random
arr = []
i = 0

# list.append(x)
for i in range(1,10):
    arr.append(random.randint(1,10))
print("list.append example:", arr)

# list.sort(key=None, reverse=False)
arr.sort()
print("list.sort example:",arr)

# list.extend(iterable)
arr.extend("testing")
print("list.extend example:", arr)

# list.insert(i,x)
arr.insert(9, 123)
print("list.insert example:", arr)

# list.remove(x)
arr.remove("t")
print("list.remove example:", arr)

# list.pop([i])
print("list.pop example:", arr.pop(), arr)

# list.index(x[,start[,end]])
print("list.index example: index of e:", arr.index("e"))

# list.count(x)
print("list.count example: count of \"s\":", arr.count("s"))

# list.reverse()
arr.reverse()
print("list.reverse example:", arr)

# list.copy()
print("list.copy example:", arr.copy())

# list.clear()
arr.clear()
print("list.clear example:",arr)