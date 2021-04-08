n = int(input())

CASE_1 = 2
CASE_2 = 3

for i in range(2, n + 1):
    if(i % CASE_1 == 0 or i % CASE_2 == 0):
        print(i)