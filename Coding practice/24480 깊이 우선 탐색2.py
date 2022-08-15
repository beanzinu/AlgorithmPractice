import sys
input = sys.stdin.readline


N,M,R = map(int,input().split(" "))
v = [ 0 for _ in range(N+1) ]
d = [[] for _ in range(N+1)]

for _ in range(M):
    a,b = map(int,input().split(" "))
    d[a].append(b)
    d[b].append(a)

q = []
q.append(R)
cnt = 1
while q:
    node = q.pop()
    if v[node]==0:
        v[node] = cnt
        cnt += 1

    for next_node in sorted(d[node]): 
        if v[next_node]==0:
            q.append(next_node)

for answer in v[1:]:
    print(answer)