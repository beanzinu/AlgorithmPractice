import sys
from collections import deque
input = sys.stdin.readline

shortcuts = [ 0 for _ in range(101) ]

N,M = map(int,input().split(" "))
for _ in range(N+M):
    a,b = map(int,input().split(" "))
    shortcuts[a] = b

dq = deque()
dq.append((1,0)) 
while dq:
    cur,cnt = map(int,dq.popleft()) # (현재위치,주사위를 굴린 횟수)  
    if 100-cur <= 6:
        print(cnt if cur==100 else cnt+1)
        break
    for i in range(1,7):
        if shortcuts[cur+i]:
            dq.append((shortcuts[cur+i],cnt+1))
    for i in range(6,0,-1):
        if shortcuts[cur+i]==0:
            dq.append((cur+i,cnt+1))
            break
        