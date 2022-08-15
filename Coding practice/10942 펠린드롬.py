import sys
input = sys.stdin.readline

N = int(input())
numbers = [0]+list(map(int,input().split(" ")))
dp = [ [0]*(N+1) for _ in range(N+1) ]

for _ in range(int(input())):
    a,b = map(int,input().split(" "))
    start,end = a,b
    flag = True
    while start<=end:
        if dp[start][end]:
            break
        elif numbers[start]==numbers[end]:
            start += 1
            end -= 1
        else:
            flag = False
            break
    dp[a][b] = int(flag)
    print(int(flag))
