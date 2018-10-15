cardNum = input()
cards = set(map(int, input().split()))

check = input()
checkNums = list(map(int, input().split()))

#print(cards)
for x in checkNums:
    if x in cards:
        print(1, end=" ")
    else:
        print(0, end=" ")
