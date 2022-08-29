import sys
input = sys.stdin.readline

n = int(input())
roads = list(map(int,input().split()))
cost = list(map(int,input().split()))

answer = 0
min_cost = cost[0]
for i in range(n-1):
    min_cost = min(min_cost,cost[i])
    answer += min_cost*roads[i]
print(answer)

