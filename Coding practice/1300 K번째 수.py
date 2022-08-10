import sys
input = sys.stdin.readline

N = int(input())
K = int(input())

# 1 2 3 4 5     
# 2 4 6 8 
# 3 6 9 12
# 4 8 12
# 5
# B를 오름차순 정렬했을때 K번째 수
start,end = 1,N**2
while start<=end:
    mid = (start+end)//2
    sum = 0
    for i in range(1,N+1):
        sum += min(mid//i,N)

    if sum >= K:
        end = mid-1
    else:
        start = mid+1 
print(end+1)