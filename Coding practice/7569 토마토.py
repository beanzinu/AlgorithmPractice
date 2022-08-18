import sys
from collections import deque
input = sys.stdin.readline

m,n,h = map(int,input().split(" "))
directions_2 = [(-1,0),(1,0),(0,1),(0,-1)]
directions_3 = [(n,0),(-n,0)]

tomatoes = [ list(map(int,input().split(" "))) for _ in range(n*h) ]

q = deque()
cnt = 0 # 토마토의 개수
for i in range(n*h):
    for j in range(m):
        if tomatoes[i][j] == 1:
            q.append((i,j,0))
        elif tomatoes[i][j] == 0:
            cnt += 1

answer = 0
while q:
    cur = q.popleft()
    i,j,day = cur[0],cur[1],cur[2]
    k = i//n # 높이
    answer = max(day,answer)

    for d in directions_2: # 상하좌우
        next_i,next_j = i+d[0],j+d[1]
        if n*k<=next_i<n*(k+1) and 0<=next_j<m and tomatoes[next_i][next_j]==0:
            tomatoes[next_i][next_j] = 1
            cnt -= 1
            q.append((next_i,next_j,day+1))
    
    for d in directions_3: # 위아래
        next_i,next_j = i+d[0],j+d[1]
        if 0<=next_i<n*h and 0<=next_j<m and tomatoes[next_i][next_j]==0:
            tomatoes[next_i][next_j] = 1
            cnt -= 1
            q.append((next_i,next_j,day+1))
    
print( answer if cnt==0 else -1 )