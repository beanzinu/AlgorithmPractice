import sys
input = sys.stdin.readline

n = int(input())
nums = list(map(int,input().split(" ")))
x = int(input())

nums.sort()
start,end = 0,n-1
answer = 0
while start <= end:
    sum = nums[start]+nums[end] 
    if sum==x and start != end:
        answer += 1
    if sum >= x:
        end -= 1
    else: 
        start += 1
print(answer)