def sum_of_n(n):
    sum = 0
    for k in range(1,n+1,1):
        sum += k
    
    return sum

print(sum_of_n(10))