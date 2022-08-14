import sys
input = sys.stdin.readline
N = int(input())
mat = []
for _ in range(N):
    mat.append(list(map(int,input().split(" "))))

## solve
dp = [ [0]*N for _ in range(N) ]
for ii in range(1,N): # window size
    for i in range(0,N-ii): # start index
        j = i+ii

        result = 0
        for k in range(i,j):
            tmp = dp[i][k]+dp[k+1][j]+mat[i][0]*mat[k][1]*mat[j][1]
            result = tmp if result==0 else min(tmp,result)
        dp[i][j]=result
print(dp[0][-1])