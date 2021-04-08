for first in range(2, 10):
    firstStr = str(first) + "*"
    
    for second in range(1, 10):
        print(firstStr + str(second) + "=" + str(first * second))

    print();
