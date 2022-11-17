import sys,heapq
from collections import defaultdict
input = sys.stdin.readline

N = int(input())
workDic = defaultdict(list)
for _ in range(N):
    deadline,profit = map(int,input().split())
    workDic[deadline].append(profit)

# O(n)
maxHeap = []
ans = 0
for i in reversed(range(1,N+1)):
    for w in workDic[i]:
        heapq.heappush(maxHeap,-w)
    if maxHeap:
        ans -= heapq.heappop(maxHeap)
print(ans)