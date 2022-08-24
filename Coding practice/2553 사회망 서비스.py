import sys
input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

n = int(input())

e = [ [] for _ in range(n+1) ]
for _ in range(n-1):
    u,v = map(int,input().split())
    e[u].append(v)
    e[v].append(u)

v = [ 0 for _ in range(n+1) ]
answer = [ 0 for _ in range(n+1) ]
def makeSNS(currentNode):
    v[currentNode] = 1
    cnt = 0 # 얼리어답터가 아닌 자식노드
    for node in e[currentNode]:
        if v[node]==0:
            makeSNS(node)
            if answer[node]==0:
                cnt += 1
    if cnt: 
        answer[currentNode] = 1
makeSNS(1)

print( answer.count(1) )