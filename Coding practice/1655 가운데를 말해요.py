import sys
import heapq
input = sys.stdin.readline

pq = [] # 오른쪽
before,mid =0,0
left=0 # 왼쪽 개수

for i in range(int(input())):
    num = int(input())
    if left >= len(pq):
        heapq.heappush(pq,num)
        mid = pq[0]
    else: # left < len(pq)
        left += 1
        if num <= mid:
            mid = max(num,before)
        else:
            heapq.heappush(pq,num)
            before = heapq.heappop(pq)
            mid = before
    print("mid:",mid)

# [1]
#  1 [5]
#  1 3 4 [5]


# 1   1     [1]  mid 1
# 5   1 5       1 [5] mid 1  left 1
# 2   1 2  5      1 [2,5]
# 10  1 2 5 10
# -99  -99 1 2 5 10
# 7  -99 1 2 5 7 10
# 5