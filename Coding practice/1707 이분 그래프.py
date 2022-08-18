import sys 
from collections import deque,defaultdict
input = sys.stdin.readline

for _ in range(int(input())):
    V,E = map(int,input().split(" "))
    d = defaultdict(list)
    for _ in range(E):
        a,b = map(int,input().split(" "))
        d[a].append(b)
        d[b].append(a)

    v = [ -1 for _ in range(V+1) ] # 0: Red , 1: Blue

    answer = True
    for start in range(1,V+1):
        if v[start] == -1:
            dq = deque()
            dq.append((start,0))
            v[start] = 0
            while dq:
                node,color = map(int,dq.popleft())
                for next_node in d[node]:
                    if v[next_node]==color:
                        answer = False
                        break
                    elif v[next_node]==-1:
                        v[next_node]= (color+1)%2 # 다른색으로
                        dq.append((next_node,v[next_node]))
        if answer==False:
            break

    print("YES" if answer else "NO")

