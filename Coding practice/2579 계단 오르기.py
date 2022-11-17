# 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
# 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
# 마지막 도착 계단은 반드시 밟아야 한다.
import sys
input = sys.stdin.readline

def solve():
    N = int(input())
    stairs = []
    for _ in range(N):
        stairs.append(int(input()))
    if N==1:
        return stairs[0]
    dp = [[0]*2 for _ in range(N)]
    dp[0][0] = stairs[0] # 첫 계단
    dp[1][0] = stairs[1]
    dp[1][1] = stairs[0]+stairs[1]
    for i in range(2,N):
        dp[i][0] = max(dp[i-2][0],dp[i-2][1]) + stairs[i]
        dp[i][1] = dp[i-1][0] + stairs[i]

    return max(dp[N-1])

print(solve())