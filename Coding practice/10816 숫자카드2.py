import sys,bisect
input = sys.stdin.readline

N = int(input())
nums = sorted(list(map(int,input().split())))
M = int(input())
for num in list(map(int,input().split())):
    a = bisect.bisect_left(nums,num)
    b = bisect.bisect_right(nums,num)
    print(b-a)
    