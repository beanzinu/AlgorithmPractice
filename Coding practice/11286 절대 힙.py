import sys
import heapq
input = sys.stdin.readline

N = int(input())
pq = []
for _ in range(N):
    num = int(input())
    if num:
        heapq.heappush(pq,(abs(num),num))
    else:
        print(heapq.heappop(pq)[1] if pq else 0)