import sys
input = sys.stdin.readline
sys.setrecursionlimit(int(1e6))

n = int(input())
weights = [0] + list(map(int,input().split()))

e = [[] for _ in range(n+1) ]
vis = [0 for _ in range(n+1)]
for _ in range(n-1):
    a,b = map(int,input().split())
    e[a].append(b)
    e[b].append(a)

dp = [ [0,weights[i]] for i in range(n+1) ] # [포함X,포함O]
nodes = [ [[],[i]] for i in range(n+1) ]

def solve(currentNode):
    vis[currentNode] = 1
    for node in e[currentNode]:
        if vis[node]==0:
            solve(node)
            if dp[node][1] > dp[node][0]:
                for n in nodes[node][1]:
                    nodes[currentNode][0].append(n)
            else:
                for n in nodes[node][0]:
                    nodes[currentNode][0].append(n)
            for n in nodes[node][0]:
                nodes[currentNode][1].append(n)
            dp[currentNode][0] += max(dp[node][0],dp[node][1])
            dp[currentNode][1] += dp[node][0]

solve(1)
print( max(dp[1]) )
if dp[1][1] > dp[1][0]:
    for node in nodes[1][1]:
        print(node,end=" ")
else:
    for node in nodes[1][0]:
        print(node,end=" ")

