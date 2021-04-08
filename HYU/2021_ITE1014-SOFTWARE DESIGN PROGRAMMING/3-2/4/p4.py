num = int(input())

starNum = 1
while starNum <= num:
    starCnt = 0

    while starCnt < starNum:
        print("*", end = " ")
        starCnt += 1

    print()
    starNum += 1
