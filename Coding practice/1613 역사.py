import sys
input = sys.stdin.readline

N,K = map(int,input().split())

edgeList = [ [0]*(N+1) for _ in range(N+1)]
for _ in range(K):
    a,b = map(int,input().split())
    edgeList[a][b] = 1

# 플로이드 와샬
for k in range(1,N+1):
    for i in range(1,N+1):
        for j in range(1,N+1):
            if edgeList[i][k] and edgeList[k][j]:
                edgeList[i][j] = 1

for _ in range(int(input())):
    a,b = map(int,input().split())
    if edgeList[a][b]:
        print(-1)
    elif edgeList[b][a]:
        print(1)
    else:
        print(0)