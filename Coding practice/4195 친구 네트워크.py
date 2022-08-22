import sys
input = sys.stdin.readline



for _ in range(int(input())): # test case
    parent = dict()
    rank = dict()
    
    def find(x):
        if x== parent[x]:
            return x
        else:
            parent[x] = find(parent[x])
            return parent[x]

    def union(x,y):
        x,y = find(x),find(y) # 부모끼리 합침
        if x==y: return x

        if rank[x] > rank[y]:
            parent[y] = x
            rank[x] += rank[y]
            return x
        else:
            parent[x] = y
            rank[y] += rank[x]
            return y

    for _ in range(int(input())):
        n1,n2 = input().split()
        for name in [n1,n2]:
            if name not in parent:
                parent[name] = name
                rank[name] = 1

        p = union(n1,n2)
        
        print( rank[find(n1)] )