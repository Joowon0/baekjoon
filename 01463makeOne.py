target = int(input())

dp = [-1, 0, 1, 1]

for x in range(4, target+1):
    cnt = dp[x-1]
    if x % 2 == 0 :
        tmp = dp[int(x/2)]
        if tmp < cnt :
            cnt = tmp
    if x % 3 == 0 :
        tmp = dp[int(x/3)]
        if tmp < cnt :
            cnt = tmp
    dp.append(cnt+1)

print(dp[target])
