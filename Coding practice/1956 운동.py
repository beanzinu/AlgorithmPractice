import sys
input = sys.stdin.readline

INF = int(1e9)
v,e = map(int,input().split(" "))

dist = [ [INF]*(v+1) for _ in range(v+1) ]
for _ in range(e):
    a,b,c = map(int,input().split(" "))
    dist[a][b] = c #순방향

for k in range(1,v+1):
    for i in range(1,v+1):
        for j in range(1,v+1):
            if dist[i][j] > dist[i][k]+dist[k][j]:
                dist[i][j] = dist[i][k]+dist[k][j]

answer = INF
for i in range(1,v+1):
    for j in range(i,v+1):
        if dist[i][j] != INF and dist[j][i] != INF:
            answer = min(answer,dist[i][j]+dist[j][i])
print( answer if answer != INF else -1)