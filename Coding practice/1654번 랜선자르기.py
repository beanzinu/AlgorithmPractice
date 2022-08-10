import sys
input = sys.stdin.readline
K,N = map(int,input().split(" "))
lines = []
for _ in range(K):
    lines.append(int(input()))

start,end = 1, lines[0]
while start <= end:
    mid = (start+end) // 2 
    total_lines = 0
    for line in lines:
        total_lines += line//mid
    if total_lines >= N:
        start = mid+1
    else:
        end = mid-1
print(end)