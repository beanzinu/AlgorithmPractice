import sys
input = sys.stdin.readline
m,n = map(int,input().split(" "))
arr = [ list(map(int,input().split(" "))) for _ in range(m) ]
dp = [ [0]*n for _ in range(m) ]
v = [ [0]*n for _ in range(m) ]
directions = [(1,0),(-1,0),(0,1),(0,-1)] 


def calc(i,j):
    if i==m-1 and j==n-1: # 목적지
        return 1
    v[i][j] = 1

    result = 0
    for direction in directions:
        next_i,next_j = i+direction[0],j+direction[1]
        if 0<=next_i<m and 0<=next_j<n and arr[next_i][next_j]<arr[i][j]:
            if dp[next_i][next_j]:
                result += dp[next_i][next_j]
            elif v[next_i][next_j]==0:
                result += calc(next_i,next_j)
    
    dp[i][j] = result
    return dp[i][j]

print( calc(0,0) )