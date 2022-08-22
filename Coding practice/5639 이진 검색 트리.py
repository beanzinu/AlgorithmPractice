import sys
input = sys.stdin.readline
sys.setrecursionlimit(int(1e9))

nums = []
while True:
    try:
        num = int(input())
        nums.append(num)
    except:
        break

def track(start,end):
    if start > end:
        return
    mid = end+1 # 오른쪽 노드 X

    for i in range(start+1,end+1):
        if nums[start] < nums[i]:
            mid = i
            break
    track(start+1,mid-1) # 왼
    track(mid,end) # 오
    print(nums[start])

track(0,len(nums)-1)
