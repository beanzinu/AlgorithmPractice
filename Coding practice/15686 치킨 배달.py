import sys
from itertools import combinations
input = sys.stdin.readline

N,M = map(int,input().split())
arr = []
for _ in range(N):
    arr.append(list(map(int,input().split())))

chickens = []
for i in range(N):
    for j in range(N):
        if arr[i][j] == 2:
            chickens.append([i,j])

def calc(chickens):
    result = 0
    for i in range(N):
        for j in range(N):
            if arr[i][j] == 1: # 집
                tmp = 2*N
                for c_i,c_j in chickens:
                    tmp = min(tmp,abs(c_i-i)+abs(c_j-j))
                result += tmp
    return result

ans = 2*N*2*N
for combination in combinations([i for i in range(len(chickens))],M):
    n_chickens = []
    for i in combination:
        n_chickens.append(chickens[i])

    ans = min(ans,calc(n_chickens))
print(ans)

