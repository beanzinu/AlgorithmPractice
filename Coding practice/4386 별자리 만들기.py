import sys
input = sys.stdin.readline

e = []
n = int(input())
for _ in range(n):
    a,b = map(float,input().split())
    e.append((a,b))

dist = []
for i in range(n):
    for j in range(i+1,n):
        d = ( (e[i][0]-e[j][0])**2 + (e[i][1]-e[j][1])**2 )**(1/2)
        dist.append((d,i+1,j+1))

answer = 0
v = [ i for i in range(n+1) ]

def find(x):
    if x==v[x]: return x
    v[x] = find(v[x])
    return v[x]

for d in sorted(dist):
    c,a,b = d[0],find(d[1]),find(d[2])
    if a==b:
        continue
    else:
        v[b] = a
        answer += c

print( round(answer,2) )