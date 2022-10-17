import sys
input = sys.stdin.readline

N,S = map(int,input().split())
numbers = list(map(int,input().split())) 

answer = N+1
end  = 0
total = numbers[0]
for start in range(N):
    while end < N and total < S:
        end += 1
        if end != N:
            total += numbers[end]
    if end == N:
        break
    answer = min(answer,end-start+1)
    total -= numbers[start]

print( answer if answer != N+1 else 0 ) 