
N,K = map(int,input().split(" "))
WV = [ list(map(int,input().split(" "))) for _ in range(N) ]
dp = [ 0 for _ in range(K+1) ]

for i in range(N):
    w,v = map(int,WV[i])
    for j in range(1,K+1):
        new_j = K+1 - j
        if w <= new_j:
            dp[new_j] = max(dp[new_j],dp[new_j-w]+v)
print(dp[K])
