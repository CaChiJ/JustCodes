import random

def getRandomString(leng):
    randomList = []
    for i in range(leng):
        randomList.append(chr(random.randint(97, 122)))
    
    ret = "".join(randomList)
    return ret


def printCheeseStatus(eaten, origin, current):
    print("Eaten alphabet of cheese :", " ".join(eaten))
    print("Original cheese :", origin)
    print("Current cheese status :", current)


def isCheeseRemain(cheese):
    for piece in cheese:
        if piece != "_":
            return True

    return False


#program start
strLen = int(input("Input the length of the string : "))

cheese = getRandomString(strLen)
currentCheese = cheese
eaten = []
allEaten = False

print("Generated Cheese is", cheese)
print("Mouse starts eating!!")

for cycle in range(10):
    eating = ''
    
    while(True):
        eating = chr(random.randint(97, 122))
        if eating not in eaten:
            eaten.append(eating)
            break;
    
    print("Start eating '" + eating +"'")

    currentCheese = currentCheese.replace(eating, "_")
    printCheeseStatus(eaten, cheese, currentCheese)

    print()
    
    # if mouse eat all of cheese
    if(not isCheeseRemain(currentCheese)):
        print("Out of cheese!")
        allEaten = True
        break


print()

# if cheese remained
if(not allEaten):
    print("Finally remained Cheese Status :")
    printCheeseStatus(eaten, cheese, currentCheese)
