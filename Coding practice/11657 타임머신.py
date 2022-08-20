import sys
import heapq
input = sys.stdin.readline

INF = int(1e9)
n,m = map(int,input().split(" "))
roads = []
for _ in range(m):
    a,b,c = map(int,input().split(" "))
    roads.append((a,b,c))

dist = [INF]*(n+1)
def bellman_ford():
    dist[1] = 0  # 시작
    for i in range(n): # (정점개수-1)만큼 반복 = 모든 노드와의 최단거리 확정 , 이후 반복에서 갱신이 이루어진다면 사이클 존재
        for j in range(m): # 간선의 개수
            a,b,c = map(int,roads[j])
            if dist[a] != INF and dist[b] > dist[a]+c:
                dist[b] = dist[a]+c
                if i == n-1: # n번의 반복에서 갱신
                    print(-1)
                    return
    for i in range(2,n+1):
            print( dist[i] if dist[i] != INF else -1 )
        
bellman_ford()
    



