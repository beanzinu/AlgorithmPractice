def solution(land):
    answer = 0
    m,n = len(land),4
    dp = []
    for j in range(4):
        dp.append(land[0][j])
        
    for i in range(m-1):
        new_dp = dp[:]
        for j in range(n):
            new_dp[j] = max(dp[:j]+dp[j+1:]) + land[i+1][j]
        dp = new_dp[:]
        
    return max(dp)