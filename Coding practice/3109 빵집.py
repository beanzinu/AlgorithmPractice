import sys
input = sys.stdin.readline

arr = []
R,C = map(int,input().split())
for _ in range(R):
    arr.append(input().replace('\n',''))

def IB(i,j):
    return not ( i<0 or i>=R or j<0 or j>=C ) 

vis = [ [ False for _ in range(C) ] for _ in range(R) ]
dir = [-1,0,1]

# 경로 찾기 : 한번 방문하면 더 이상 방문할 필요 없음.
def dfs(i,j):
    vis[i][j] = True
    # 끝점
    if j==C-1:
        return True
    for d in dir:
        if IB(i+d,j+1) and arr[i+d][j+1]=="." and not vis[i+d][j+1]:
            if dfs(i+d,j+1):
                return True
    return False

ans = 0
for i in range(R):
    ans += dfs(i,0)
print(ans)



