import sys
input = sys.stdin.readline

for _ in range(int(input())):
    N = int(input())
    points = []
    for _ in range(N+2):
        points.append(list(map(int,input().split())))

    vis = [ [0]*(N+2) for _ in range(N+2) ]
    # O(n^2)
    for i in range(N+2):
        for j in range(i+1,N+2):
            if abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]) <= 1000:
                vis[i][j] = 1
                vis[j][i] = 1
    # O(n^3)
    for k in range(N+2):
        for i in range(N+2):
            for j in range(N+2):
                if vis[i][k] and vis[k][j]:
                    vis[i][j] = 1

    print( "happy" if vis[0][N+1] else "sad" )
