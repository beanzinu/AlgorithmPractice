K,N = map(int,input().split())
nums = []
for _ in range(K):
    nums.append(int(input()))
nums.sort()
s,e = 0,nums[-1]
ans = 0

while s <= e:
    mid = (s+e)//2
    total = 0
    for n in nums:
        total += n//mid
    if total < N:
        e = mid-1
    else:
        ans = mid
        s = mid+1

print(ans)


