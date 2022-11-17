import sys,copy
input = sys.stdin.readline

N,M = map(int,input().split())
arr = []
for _ in range(N):
    arr.append( list(map(int,input().split())))

# 1~5
points = []
for i in range(N):
    for j in range(M):
        if 1<= arr[i][j] <= 5:
            points.append([i,j])

# 상우하좌
dx = [-1,0,1,0]
dy = [0,1,0,-1]

def OOB(i,j):
    return (i<0 or i>=N or j<0 or j>=M)

def fill(i,j,dir,arr):
    dir %= 4
    while 1:
        i += dx[dir]
        j += dy[dir]
        if OOB(i,j) or arr[i][j]==6:
            return
        if arr[i][j]==0:
            arr[i][j] = 7
        
ans = sum( a.count(0) for a in arr )
for i in range(4**len(points)): # 4진수로 points 개수에 대하여 방향 정함
    cur = i
    n_arr = copy.deepcopy(arr)
    for x,y in points:
        dir = cur%4
        cur //= 4
        if arr[x][y] == 1:
            fill(x,y,dir,n_arr)
        elif arr[x][y] == 2:
            fill(x,y,dir,n_arr)
            fill(x,y,dir+2,n_arr)
        elif arr[x][y] == 3:
            fill(x,y,dir,n_arr)
            fill(x,y,dir+1,n_arr)
        elif arr[x][y] == 4:
            fill(x,y,dir,n_arr)
            fill(x,y,dir+1,n_arr)
            fill(x,y,dir+2,n_arr)
        elif arr[x][y] == 5:
            fill(x,y,dir,n_arr)
            fill(x,y,dir+1,n_arr)
            fill(x,y,dir+2,n_arr)
            fill(x,y,dir+3,n_arr)

    result = 0
    for n in range(N):
        for m in range(M):
            result += (n_arr[n][m]==0)
    ans = min(ans,result)

print(ans)