import sys
from collections import deque
input = sys.stdin.readline

n,q = map(int,input().split())
edges = [[] for _ in range(n+1)]
for _ in range(n-1):
    a,b,c = map(int,input().split())
    edges[a].append((b,c))
    edges[b].append((a,c))

for _ in range(q):
    k,v = map(int,input().split())
    q = deque()
    count = 0
    vis = [ 0 for _ in range(n+1) ]
    vis[v] = 1
    q.append(v)
    while q:
        node = q.pop()
        for new_node,value in edges[node]:
            if vis[new_node]==0 and value >= k:
                count += 1
                vis[new_node] = 1
                q.append(new_node)
    print(count)