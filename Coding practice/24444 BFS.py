import sys
input = sys.stdin.readline

N,M,R = map(int,input().split(" "))
edges = [[] for _ in range(N+1)]
answer = [ 0 for _ in range(N+1)]

for _ in range(M):
    a,b = map(int,input().split(" "))
    edges[a].append(b)
    edges[b].append(a)

q = []
q.append(R)
answer[R] = 1
cnt = 2
while q:
    node = q.pop(0)

    for next_node in sorted(edges[node],reverse=True):
        if answer[next_node]==0:
            answer[next_node] = cnt
            cnt += 1
            q.append(next_node)

for a in answer[1:]:
    print(a)