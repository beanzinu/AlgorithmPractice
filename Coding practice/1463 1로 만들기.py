import sys
input = sys.stdin.readline

N = int(input())
dp = [ 0 for _ in range(N+1)]
for i in range(2,N+1):
    res = dp[i-1]+1
    if i%3==0:
        res = min(res,dp[i//3]+1)
    if i%2==0:
        res = min(res,dp[i//2]+1)
    dp[i] = res
print(dp[N])
