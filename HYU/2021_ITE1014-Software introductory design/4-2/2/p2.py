def problemDescription():
    print("* Number of divisors *")


def getNumOfDivisors(number):
    ret = 0

    for i in range(1, number+1):
        if(number % i == 0):
            ret += 1
    
    return ret


problemDescription()

print("Type the first Number:")
num1 = int(input())
print("Type the second number:")
num2 = int(input())

print("Number of divisors of the first number is {}".format(getNumOfDivisors(num1)))
print("Number of divisors of the second number is {}".format(getNumOfDivisors(num2)))