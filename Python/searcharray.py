arr = [1,2,3,4,5,6,7,8,9,10]
search = 10

for i in range(1,10):
    if arr[i] == search:
        print(search, "is in the list in position", i)
        break;