import sys
input = sys.stdin.readline

N,C = map(int,input().split(" "))
homes = [ int(input()) for _ in range(N)]
### solve
homes.sort()
start,end = 1,homes[-1]-homes[0]
while start<=end:
    mid = (start+end)//2
    total = 1 # 첫번째 집
    before = homes[0]
    for home in homes[1:]:
        if home-before >= mid:
            total += 1
            before = home
    if total >= C:
        start = mid+1
    else:
        end = mid-1

print(end)
