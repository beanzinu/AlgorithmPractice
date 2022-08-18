import sys
import heapq
input = sys.stdin.readline

# 최단 거리
# 1 -> ... -> v1 -> ... -> v2 -> ... -> N
# 1 -> ... -> v2 -> ... -> v1 -> ... -> N

N,E = map(int,input().split(" "))
e = [ [1001]*(N+1) for _ in range(N+1) ]
for _ in range(E):
    a,b,c = map(int,input().split(" "))
    e[a][b] = c
    e[b][a] = c
v1,v2 = map(int,input().split(" "))

answer = []
for start in [1,v1,v2]:
    d = [ 100001 for _ in range(N+1) ]
  
    d[start]=0
    pq = [(0,start)]
    while pq:
        cost,node = map(int,heapq.heappop(pq))
        for i in range(1,N+1):
            if d[i] > d[node]+e[node][i]:
                d[i] = d[node]+e[node][i]
                heapq.heappush(pq,(d[i],i))
    answer.append(d)
result = min(answer[0][v1]+answer[1][v2]+answer[2][N],answer[0][v2]+answer[2][v1]+answer[1][N])
print( result if result < 1000*2*(N-1) else -1 )