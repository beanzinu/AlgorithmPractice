import sys
input = sys.stdin.readline

n = int(input())
d = dict()
for _ in range(n):
    name,state = map(str,input().split())
    d[name] = state

for name in sorted(d,reverse=True):
    if d[name] == "enter":
        print(name)
