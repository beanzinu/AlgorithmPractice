import sys
input = sys.stdin.readline

directions = [(2,1),(2,-1),(-1,-2),(-1,2),(1,-2),(1,2),(-2,-1),(-2,1)]

for _ in range(int(input())):
    n = int(input())
    v = [ [0]*n for _ in range(n) ]
    x,y = map(int,input().split(" "))
    nx,ny = map(int,input().split(" "))
    q = [(x,y,0)]
    while q:
        cur = q.pop(0)
        if cur[0]==nx and cur[1]==ny:
            print(cur[2])
            break
        for direction in directions:
            next_x,next_y = cur[0]+direction[0],cur[1]+direction[1]
            if 0<=next_x<n and 0<=next_y<n:
                if v[next_x][next_y]==0:
                    v[next_x][next_y] = 1
                    q.append((next_x,next_y,cur[2]+1))

