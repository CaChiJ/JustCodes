def add(a, b):
    return a + b

def sub(a, b):
    return a - b

def mul(a, b):
    return a * b

def div(a, b):
    return a / b

def mod(a, b):
    return a % b

def printMsg():
    print("completed")
    return

a = int(input())
b = int(input())
print("sum: " + str(add(a, b)))
print("difference: " + str(sub(a, b)))
print("product: " + str(mul(a, b)))
print("division: " + str(div(a, b)))
print("remainder: " + str(mod(a, b)))
printMsg()