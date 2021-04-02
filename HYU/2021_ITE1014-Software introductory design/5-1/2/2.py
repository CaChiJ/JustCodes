import random

#난수 생성
randoms = []
for i in range(100):
    randoms.append(random.randint(1, 1000))

#난수 리스트의 요소 출력
for i in randoms:
    print(i, end=" ")

print()

#최댓값 출력
max = 0
for i in randoms:
    if(i > max):
        max = i

print(max)
