import random

def getRandomString(leng):
    randomList = []
    for i in range(leng):
        randomList.append(chr(random.randint(97, 122)))
    
    ret = "".join(randomList)
    return ret

inputLen = int(input())
print(getRandomString(inputLen))
