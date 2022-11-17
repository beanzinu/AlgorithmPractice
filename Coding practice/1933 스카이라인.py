import sys,heapq
from collections import defaultdict
input = sys.stdin.readline

LEFT = 0
RIGHT = 1

ans_dic = defaultdict(int)
points = []
n = int(input())
for _ in range(n):
    l,h,r = map(int,input().split())
    points.append((LEFT,l,h,r))
    points.append((RIGHT,r,h))

rightHeap = []
check = set()
# 각 사각형의 왼쪽,오른쪽 끝점 죄표들
for i,p in enumerate(sorted(points,key=lambda x:(x[1],x[0],-x[2]))):
    
    if p[0] == LEFT:
        r_max = -rightHeap[0][0] if rightHeap else 0

        # 현재 좌표에서의 최대 높이 < 사각형의 높이
        if r_max < p[2]:
            ans_dic[p[1]] = p[2]
        # 사각형의 오른쪽 죄표 추가
        heapq.heappush(rightHeap,(-p[2],p[3]))
    else: # RIGHT
        # 현재 오른쪽 끝점 추가
        check.add(p[1])
        # 현재 좌표보다 같거나 같은 오른쪽 끝점 제거(사각형 제거)
        while rightHeap and rightHeap[0][1] in check:
            heapq.heappop(rightHeap)
        r_max = -rightHeap[0][0] if rightHeap else 0
        
        # 현재 좌표에서의 최대 높이 < 사각형의 높이
        if r_max==0:
            ans_dic[p[1]] = 0
        elif r_max < p[2]:
            ans_dic[p[1]] = r_max

for key in ans_dic:
    print(str(key),str(ans_dic[key]),end=' ')


