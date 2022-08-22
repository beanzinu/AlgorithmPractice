import sys
input = sys.stdin.readline

n = int(input())
values = list(map(int,input().split(" ")))

values.sort()
start,end = 0,n-1
answer = (0,0)
answer_sum = 2000000000
while start<=end:
    values_sum = values[start]+values[end]
    if answer_sum > abs(values_sum):
        if start != end: # answer
            answer = (values[start],values[end])
            answer_sum = abs(values_sum)
    if start==n-1 or end==0:
        break
    if abs(values[start+1]+values[end]) < abs(values[start]+values[end-1]):
        start += 1
    else:
        end -= 1 
print(answer[0],answer[1])