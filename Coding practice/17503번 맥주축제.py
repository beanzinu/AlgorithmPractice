import heapq
import sys
input = sys.stdin.readline
N,M,K = map(int,input().split(" "))
# 선호도 레벨
VC = [ list(map(int,input().split(" "))) for _ in range(K) ]

# N일동안 선호도 M 이상 
# N개의 맥주 중 가장 높은 도수
# 맥주는 중복해서 마실 수 없다.
# 낮은 도수부터 넣기
result = []
total_v = 0
for v,c in sorted(VC,key=lambda x:(x[1],x[0])):
    total_v += v
    heapq.heappush(result,v)
    if len(result) == N: # 선호도의합 >= M
        if total_v >= M:
            print(c)
            break
        else:
            total_v -= heapq.heappop(result)
else:
    print(-1)


        
