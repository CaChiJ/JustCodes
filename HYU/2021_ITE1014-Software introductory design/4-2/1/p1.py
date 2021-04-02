def printLine(n):
    for i in range(1, n+1):
        print(i, end=' ')

    print()

n = int(input())

for i in range(1, n+1):
    printLine(i)

for i in range(n, 0, -1):
    printLine(i)
