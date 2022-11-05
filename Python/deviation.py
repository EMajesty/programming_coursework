import statistics
arr = [1,2,3,4,5,6,7,8]

def deviation(arr):
    return statistics.stdev(arr)
    

print(deviation(arr))