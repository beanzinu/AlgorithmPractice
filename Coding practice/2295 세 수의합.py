import bisect
N = int(input())

# O(nlogn)
nums = set()
for _ in range(N):
    nums.add(int(input()))
nums = sorted(list(nums))

twoSum = set()
# (N^2 + nlogn)
for i in range(N):
    for j in range(i,N):
        twoSum.add(nums[i]+nums[j])
twoSum = sorted(list(twoSum))

def solve():
    # O(n^2logn)
    for i in reversed(range(N)):
        for j in range(i,-1,-1):
            targetNum = nums[i]-nums[j]
            findNum = twoSum[bisect.bisect_left(twoSum,targetNum)]
            if targetNum==findNum:
                return nums[i]
print( solve() )