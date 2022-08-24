import sys
input = sys.stdin.readline

n,m = map(int,input().split())

points = [] # 별들의 위치
for _ in range(n):
    a,b = map(int,input().split())
    points.append((a,b))
 
e = [] # 간선 : (거리,별1,별2)
for i in range(n):
    for j in range(i+1,n):
        d = ( (points[i][0]-points[j][0])**2+(points[i][1]-points[j][1])**2 )**0.5
        e.append((d,i+1,j+1))

parent = [ i for i in range(n+1) ] # union-find
def find(x):
    if x==parent[x]: return x
    parent[x] = find(parent[x])
    return parent[x]

for _ in range(m):
    a,b = map(int,input().split())
    a,b = find(a),find(b)
    parent[b] = a

answer = 0 # 간선의 weights 합
for ee in sorted(e):
    c,a,b = ee[0],find(ee[1]),find(ee[2])
    if a==b:
        continue
    else:
        parent[b] = a
        answer += c
        
print("{:.2f}".format(answer))
    
