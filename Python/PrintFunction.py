import sys
if __name__ == '__main__':
    n = int(input())
    res = int(0)
    for i in range(1, n + 1):
	sys.stdout.write(str(i))
	sys.stdout.flush()

