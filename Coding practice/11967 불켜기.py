import sys
from collections import deque
input = sys.stdin.readline

N,M = map(int,input().split())
directions = [(-1,0),(1,0),(0,-1),(0,1)]


lights = [ [ [] for _ in range(N+1)] for _ in range(N+1)]
for _ in range(M):
    x,y,a,b = map(int,input().split())
    lights[x][y].append([a,b])

ans = [ [False]*(N+1) for _ in range(N+1) ] # 불 켜져있는지 여부
vis = [ [False]*(N+1) for _ in range(N+1) ] # 방문했는지 여부
dq = deque()
dq.append([1,1])
vis[1][1] = True

def IB(i,j):
    return not (i<=0 or i>N or j<=0 or j>N)

while dq:
    x,y = map(int,dq.popleft())
    ans[x][y] = True
    
    for a,b in lights[x][y]:
        if not ans[a][b]:
            ans[a][b] = True
            # 불을 킨 방 상하좌우에 방문가능한 방이 있을 시
            for d in directions:
                next_a,next_b = a+d[0],b+d[1]
                if IB(next_a,next_b) and vis[next_a][next_b]:
                    vis[a][b] = True
                    dq.append([a,b])
                    break
        
    # 상하좌우에 불은 켜져있는데 방문안한 방
    for d in directions:
        next_x,next_y = x+d[0],y+d[1]
        if IB(next_x,next_y) and not vis[next_x][next_y] and ans[next_x][next_y]:
            vis[next_x][next_y] = True
            dq.append([next_x,next_y])

print( sum(map(sum,ans)) )


