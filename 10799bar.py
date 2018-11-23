lasers = input()

stickNum = 0
totalStick = 0

for i in range(len(lasers)):
    if lasers[i] == '(':
        stickNum += 1
    if lasers[i] == ")":
        if lasers[i-1] == "(":
            stickNum -= 1
            totalStick += stickNum
        else:
            stickNum -= 1
            totalStick += 1
    #print(i, lasers[i], stickNum, totalStick)

print(totalStick)

