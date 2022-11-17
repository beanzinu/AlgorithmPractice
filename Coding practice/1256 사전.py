import sys
import math
input = sys.stdin.readline
comb = math.comb

N,M,K = map(int,input().split())

if comb(N+M,N) < K:
    print(-1)
else:
    ans = ""
    position = 0
    for i in range(N+M):
        if N==0:
            ans += "z"
            M -= 1
        elif M==0:
            ans += "a"
            N -= 1
        elif position+comb(N+M-1,N-1) >= K:
            ans += "a"
            N -= 1
        else: # comb(N+M-1,N-1) < K:
            ans += "z"
            position += comb(N+M-1,N-1)
            M -= 1
    print(ans)