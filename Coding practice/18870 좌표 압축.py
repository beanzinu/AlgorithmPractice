import sys,bisect
input = sys.stdin.readline

N = int(input())
arr = list(map(int,input().split()))
nums = sorted(list(set((arr))) )
for a in arr:
    print( bisect.bisect_left(nums,a),end=" ")
