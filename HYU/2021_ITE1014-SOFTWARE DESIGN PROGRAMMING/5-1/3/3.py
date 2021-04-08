inputs = input().split()

inputDict = {}
for i in inputs:
    if i in inputDict:
        inputDict[i] += 1
    else:
        inputDict[i] = 1

for key in list(inputDict.keys()):
    print(key + ": " + str(inputDict[key]))

    
