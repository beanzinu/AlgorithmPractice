import sys
from collections import defaultdict
input = sys.stdin.readline
sys.setrecursionlimit(100000)

N,M,R = map(int,input().split(" "))
d = defaultdict(list)
answer = [0 for _ in range(N+1)]
for _ in range(M):
    a,b = map(int,input().split(" "))
    d[a].append(b)
    d[b].append(a)


global cnt
cnt = 1
def dfs(current):
    global cnt
    if answer[current]==0:
        answer[current] = cnt
        cnt += 1
    if current in d:
        for next in sorted(d[current]):
            if answer[next]==0:
                dfs(next)
    
dfs(R)

for a in answer[1:]:
    print(a)