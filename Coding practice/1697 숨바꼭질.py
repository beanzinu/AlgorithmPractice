import sys
input = sys.stdin.readline

N,K = map(int,input().split(" "))

q = []
v = [ 0 for _ in range(200000) ]
q.append((0,N))

while q:
    cur = q.pop(0)
    if cur[1]==K:
        print(cur[0])
        break
    next_nodes = [cur[1]+1,cur[1]-1,cur[1]*2]
    for next_node in next_nodes:
        if next_node < 200000 and next_node>=0 and v[next_node]==0:
            v[next_node]=1
            q.append((cur[0]+1,next_node))

