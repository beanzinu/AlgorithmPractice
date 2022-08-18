import sys
from collections import deque
input = sys.stdin.readline

m,n = map(int,input().split(" "))
tomatoes = [ list(map(int,input().split(" "))) for _ in range(n) ]
directions = [(-1,0),(1,0),(0,1),(0,-1)]

cnt = 0
q = deque()
for i in range(n): # 총 토마토 개수
    for j in range(m):
        if tomatoes[i][j]==0:
            cnt += 1
        elif tomatoes[i][j]==1:
            q.append((i,j,0))

answer = 0
while q:
    cur = q.popleft()
    i,j,day = cur[0],cur[1],cur[2]
    answer = max(day,answer)
    for d in directions:
        next_i,next_j = i+d[0],j+d[1]
        if 0<=next_i<n and 0<=next_j<m and tomatoes[next_i][next_j]==0:
            tomatoes[next_i][next_j]=1
            cnt -= 1
            q.append((next_i,next_j,day+1))
print( answer if cnt==0 else -1 )