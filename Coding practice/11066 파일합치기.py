import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    K = int(input()) 
    files = list(map(int,input().split(" ")))
    pre_sum = files[:]
    for i,file in enumerate(files[1:]):
        pre_sum[i] += pre_sum[i-1]
    DP = [ [ 0 for _ in range(K) ] for _ in range(K) ]

    def dp(a,b): # dp를 활용한 재귀
        if a==b:
            return files[a]
        if DP[a][b]:
            return DP[a][b]    

        ret = 0
        for i in range(a,b):
            result = dp(a,i)+dp(i+1,b) + pre_sum[b+1]-pre_sum[a]
            ret = result if ret==0 else min(result,ret)
        DP[a][b] = ret
        return ret

    answer = 0
    for i in range(0,K-1):
        result = dp(0,i) + dp(i+1,K-1)
        answer =  result if answer==0 else min(answer,result)
    print(answer)


