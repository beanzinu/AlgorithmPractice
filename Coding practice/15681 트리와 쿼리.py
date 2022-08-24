import sys
input = sys.stdin.readline
sys.setrecursionlimit(1e9)

n,r,q = map(int,input().split())
e = [ [] for _ in range(n+1) ]
for _ in range(n-1):
    a,b = map(int,input().split())
    e[a].append(b)
    e[b].append(a)

child = [ [] for _ in range(n+1) ]
def makeTree(currentNode,parent):
    for node in e[currentNode]:
        if node != parent:
            child[currentNode].append(node)
            makeTree(node,currentNode)
makeTree(r,-1)

size = [0 for _ in range(n+1)]
def countSubtreeNodes(currentNode):
    size[currentNode] = 1
    for node in child[currentNode]:
        countSubtreeNodes(node)
        size[currentNode] += size[node]

countSubtreeNodes(r)
for _ in range(q):
    print( size[int(input())] )
