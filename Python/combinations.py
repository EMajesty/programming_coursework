from itertools import combinations 

def combination(arr, r):
    return list(combinations(arr, r))

asdf = [1,2,3,4]
print(combination(asdf,2))