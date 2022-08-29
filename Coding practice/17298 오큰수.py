import sys
input = sys.stdin.readline

n = int(input())
numbers = list(map(int,input().split()))

answer = [ -1 for _ in range(n) ]
stack = []
for i,number in enumerate(numbers):
    while stack and stack[-1][1] < number:
        end = stack.pop()
        answer[end[0]] = number
    stack.append((i,number))

for a in answer:
    print(a,end=" ")