import sys
import heapq
from collections import defaultdict
input = sys.stdin.readline

# Test Case
for _ in range(int(input())):
    # 연산개수
    k = int(input())
    count_dict = defaultdict(int)
    max_heap = []
    min_heap = []
    for _ in range(k):
        op,num = map(str,input().split())
        num = int(num.replace("\n",""))
        if op=="I":
            count_dict[num] += 1
            heapq.heappush(min_heap,num)
            heapq.heappush(max_heap,-num)
        elif op=="D": 
            if num == 1 and max_heap: # 최대값 삭제
                while max_heap:
                    pop_num = -heapq.heappop(max_heap)
                    if count_dict[pop_num]:
                        count_dict[pop_num] -= 1
                        break
            elif num == -1 and min_heap: # 최소값 삭제
                while min_heap:
                    pop_num = heapq.heappop(min_heap)
                    if count_dict[pop_num]:
                            count_dict[pop_num] -= 1
                            break

    ans = []
    for c in count_dict:
        if count_dict[c]:
            ans.append(c)
    if not ans:
        print("EMPTY")
    else:
        print(max(ans),min(ans))
