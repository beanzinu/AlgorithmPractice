import sys
input = sys.stdin.readline

N = int(input())
arr = [ [ 0 for _ in range(N+1)]]
for _ in range(N):
    arr.append( [0] + list(map(int,input().split())))


W,H,D = 0,1,2
dp = [ [ [0]*3 for _ in range(N+1) ] for _ in range(N+1) ] # dp[N+1][N+1][3]
dp[1][2][W] = 1
for i in range(1,N+1):
    for j in range(1,N+1):
        if j+1<=N and not arr[i][j+1]:
            if i==1 and j+1==2:
                continue
            dp[i][j+1][W] = dp[i][j][D] + dp[i][j][W]
        if i+1<=N and not arr[i+1][j]:
            dp[i+1][j][H] = dp[i][j][H] + dp[i][j][D]
        if (i+1<=N and j+1<=N) and not( arr[i][j+1] or arr[i+1][j] or arr[i+1][j+1]):
            dp[i+1][j+1][D] = dp[i][j][D] + dp[i][j][W] + dp[i][j][H]
print( sum(dp[N][N]) )

