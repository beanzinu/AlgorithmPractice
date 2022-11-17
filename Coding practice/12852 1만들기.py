import sys
input = sys.stdin.readline

X = int(input())

dp = [[] for _ in range(X+1)]
dp[1].append(1)


for i in range(2,X+1):
    dp[i] = dp[i-1][:]
    if i%2==0 and len(dp[i//2]) < len(dp[i]):
        dp[i] = dp[i//2][:]
    if i%3==0 and len(dp[i//3]) < len(dp[i]):
        dp[i] = dp[i//3][:]
    dp[i].append(i)

print(len(dp[X])-1)
for num in reversed(dp[X]):
    print(num,end=" ")