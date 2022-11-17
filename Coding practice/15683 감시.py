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

def fill(i,j,di,dj,arr):
    while 0<= i+di < N and 0<= j+dj < M and arr[i+di][j+dj] != 6:
        if arr[i+di][j+dj] == 0:
            arr[i+di][j+dj] = 7
        i += di
        j += dj

directions = [ 
    [ [[1,0]],[[0,1]],[[0,-1]],[[-1,0]] ],
    [ [[1,0],[-1,0]],[[0,1],[0,-1]] ],
    [ [[-1,0],[0,1]],[[-1,0],[0,-1]],[[0,1],[1,0]],[[0,-1],[1,0]] ],
    [ [[-1,0],[0,-1],[0,1]],[[-1,0],[0,1],[1,0]],[[0,1],[1,0],[0,-1]],[[-1,0],[1,0],[0,-1]]],
    [[[-1,0],[1,0],[0,1],[0,-1]]]
]

global ans
ans = N*M
def DFS(points,arr):
    global ans
    if not points:
        result = 0
        for i in range(N):
            for j in range(M):
                if arr[i][j] == 0:
                    result += 1
        ans = min(result,ans)
        return
    i,j = points[0][0],points[0][1]
    for direction in directions[arr[i][j]-1]: # [[1,0],[-1,0]],[[0,1],[0,-1]]
        n_arr = copy.deepcopy(arr)
        for di,dj in direction:  # [[1,0],[-1,0]]
            fill(i,j,di,dj,n_arr)
        DFS(points[1:],n_arr)   

DFS(points,arr)

print(ans)