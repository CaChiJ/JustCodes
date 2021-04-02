def addTotal(num):
    ret = 0

    for i in range(1, num + 1):
        ret += int(i)
    
    return ret


def mulTotal(num):
    global gMul
    gMul = 1

    for i in range(1, num + 1):
        gMul *= int(i)
    
    return


gMul = 1
n = int(input())

print('addTotal(): ' + str(addTotal(n)))
mulTotal(n)
print('gMul: ' + str(gMul))
