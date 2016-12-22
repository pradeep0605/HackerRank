import sys

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    if n % 2 == 1:
	print("Weird\n")
    else:
	if n >= 2 and n <= 5:
	    print("Not Weird\n")
	if n >= 6 and n <= 20:
	    print("Weird\n")
	if n > 20:
	    print("Not Weird\n")
	    
                
