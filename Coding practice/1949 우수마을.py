import sys
input = sys.stdin.readline
sys.setrecursionlimit(int(1e6))

n = int(input())
people = [0] + list(map(int,input().split()))
e = [[] for _ in range(n+1)]
for _ in range(n-1):
    a,b = map(int,input().split())
    e[a].append(b)
    e[b].append(a)

dp = [ [people[i],0] for i in range(n+1) ] # (우수마을O,우수마을X)
vis = [ 0 for _ in range(n+1)]

def solve(currentNode):
    vis[currentNode] = 1
    for node in e[currentNode]:
        if vis[node]==0: # child
            solve(node)
            dp[currentNode][0] += dp[node][1] # O - XX
            dp[currentNode][1] += max(dp[node][0],dp[node][1]) # X - OX/XO/XX

solve(1)
print( max(dp[1]) )