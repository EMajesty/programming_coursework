import operator

arr1 = [1,2,3,4,5]
arr2 = [6,7,8,9,10]

arrsum = list(map(operator.add,arr1,arr2))

print(arrsum)