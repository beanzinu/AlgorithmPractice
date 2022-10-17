import sys
import heapq
input = sys.stdin.readline
N,K = map(int,input().split())

jewels = [] # 높은 가치의 보석 heapq
for _ in range(N):
    m,v = map(int,input().split())
    heapq.heappush(jewels,(m,v))

caps = []
for _ in range(K):
    caps.append(int(input()))
# O(KlogK)
caps.sort()

ans = 0
max_values = []
# O(KlogN)?
for cap in caps:
    while jewels and jewels[0][0] <= cap:
        heapq.heappush(max_values,-heapq.heappop(jewels)[1])
    if max_values:
        ans -= heapq.heappop(max_values)

print(ans)


