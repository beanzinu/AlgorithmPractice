import sys,heapq
input = sys.stdin.readline

def solve(N,arr):
    vis = [[False]*N for _ in range(N)]
    directions = [(-1,0),(1,0),(0,1),(0,-1)]
    minHeap = [(arr[0][0],0,0)] # (거리,i,j)

    def IB(i,j):
        return not (i<0 or i>=N or j<0 or j>=N)

    # 거리가 짧은 것부터 찾기
    while minHeap:
        dist,i,j = heapq.heappop(minHeap)
        if i==N-1 and j==N-1:
            return dist
        for d in directions:
            n_i,n_j = i+d[0],j+d[1]
            if IB(n_i,n_j) and not vis[n_i][n_j]:    
                vis[n_i][n_j] = True
                heapq.heappush(minHeap,(dist+arr[n_i][n_j],n_i,n_j))
    
index = 1
while True:
    N = int(input())
    if N==0: break
    arr = []
    for _ in range(N):
        arr.append( list(map(int,input().split())))
    print(f'Problem {index}: {solve(N,arr)}')
    index += 1
