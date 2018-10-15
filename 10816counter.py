from collections import Counter

cardNum = input()
cards = list(map(int, input().split()))

cn = Counter(cards)
#print(cn)

check = input()
checkNums = list(map(int, input().split()))

for x in checkNums:
    print(cn[x], end=' ')
