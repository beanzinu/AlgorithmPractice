import sys
input = sys.stdin.readline

N,M = map(int,input().split(" "))
heights = list( map(int,input().split(" ")) )

start,end = 0,max(heights)
while start<=end:
    mid = (start+end)//2
    take = 0
    for height in heights:
        take += height-mid if height-mid>0 else 0
    if take >= M:
        start = mid+1
    else:
        end = mid-1

print(end)
