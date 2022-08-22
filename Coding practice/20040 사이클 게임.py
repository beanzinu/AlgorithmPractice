import sys
input = sys.stdin.readline

n,m = map(int,input().split())
parent = [ i for i in range(n) ]
rank = [ 1 for i in range(n) ]

def find(x):
    if parent[x]==x: return x
    parent[x] = find(parent[x])
    return parent[x]

def union(x,y):
    x = find(x)
    y = find(y)
    if x==y: return False
    
    if rank[x] > rank[y]:
        parent[y] = x
        rank[x] += rank[y]
    else:
        parent[x] = y
        rank[y] += rank[x]
    return True 

for i in range(m):
    a,b = map(int,input().split())
    a,b = find(a),find(b)

    if not union(a,b):
        print(i+1)
        break
else:
    print(0)