import sys
input = sys.stdin.readline

N,M = map(int,input().split())
nums = list(map(int,input().split()))
preSum = [0]

nSum = 0
for num in nums:
    nSum += num
    preSum.append(nSum)

for _ in range(M):
    i,j = map(int,input().split())
    print( preSum[j]-preSum[i-1] )
    