import sys
input = sys.stdin.readline

N,M = map(int,input().split(" "))
arr1 = [ list(map(int,input().split(" "))) for _ in range(N) ]
M,K = map(int,input().split(" "))
arr2 = [ list(map(int,input().split(" "))) for _ in range(M) ]

for i in range(N):
    for j in range(K):
        sum = 0
        for n in range(M):
            sum += arr1[i][n] * arr2[n][j]
        print(sum,end=" ")
    print()