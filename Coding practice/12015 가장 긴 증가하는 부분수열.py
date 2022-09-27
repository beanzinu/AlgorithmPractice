import sys
input = sys.stdin.readline

n = int(input())
numbers = list(map(int,input().split()))

memoization = [0]

for number in numbers:
    if number > memoization[-1]:
        memoization.append(number)
    else:
        left,right = 0,len(memoization)
        while left < right:
            mid = (left+right)//2
            if memoization[mid] < number:
                left = mid+1
            else:
                right = mid
        memoization[right] = number

print( len(memoization)-1 )