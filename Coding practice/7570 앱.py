import sys
input = sys.stdin.readline

N,M = map(int,input().split(" "))
memories = list(map(int,input().split(" ")))
costs = list(map(int,input().split(" ")))

max_c = N*100+1
dp = [ 0 for _ in range(max_c+1)]

for i in range(N):
    memory,cost = memories[i],costs[i]
    for j in range(max_c,0,-1):
        if j-cost >= 0:
            dp[j] = max(dp[j-cost]+memory,dp[j])

for i,memory in enumerate(dp):
    if memory >= M:
        print(i)
        break
