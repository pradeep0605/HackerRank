import sys
if __name__ == '__main__':
    n = int(sys.stdin.readline())
    array = sys.stdin.readline().strip().split(" ")
    for i in range(0, n):
        # convert to an integer array
        array[i] = int(array[i])
    
    tup = tuple(array)
    print(hash(tup))
    
