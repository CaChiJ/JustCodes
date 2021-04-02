name1, score1 = input().split();
name2, score2 = input().split();
name3, score3 = input().split();

dic = {}

dic[name1] = int(score1)
dic[name2] = int(score2)
dic[name3] = int(score3)

print("Which student's score?")
who = input()
if who in dic:
    print(who + "'s score:", dic[who])
else:
    print(who, "is not in the database.")
