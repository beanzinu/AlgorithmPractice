import sys
input = sys.stdin.readline

N = int(input())
arr = []
for _ in range(N):
    arr.append( list(map(int,input().split())))

def solve():
    global ans
    ans = 0

    W,H,D = 0,1,2
    directions = [
        [(0,1,0,1,W),(0,1,1,1,D)], # 가로
        [(1,0,1,0,H),(1,0,1,1,D)], # 세로
        [(1,1,0,1,W),(1,1,1,0,H),(1,1,1,1,D)]  # 대각선
    ]
    move = [(0,1),(1,0),(1,1)]

    def IB(i,j,k,l,form):
        if (i<0 or i>=N or j<0 or j>=N) or (k<0 or k>=N or l<0 or l>=N):
            return False
        if form in [W,H]:
            return arr[i][j]==0 and arr[k][l]==0
        else: # D
            return arr[i][j]==0 and arr[i][j+1]==0 and arr[i+1][j]==0 and arr[k][l]==0


    vis = [ [ [-1]*3 for _ in range(N) ] for _ in range(N)] # memoization

    def DFS(i,j,form):
        k,l = i+move[form][0],j+move[form][1]
        if k==N-1 and l==N-1:
            return 1
        if vis[i][j][form] != -1:
            return vis[i][j][form]
        
        result = 0 
        for d in directions[form]:
            ni,nj,nk,nl = i+d[0],j+d[1],k+d[2],l+d[3]
            if IB(ni,nj,nk,nl,d[4]):
                result += DFS(ni,nj,d[4])
        vis[i][j][form] = result
        return result                
        
    
    DFS(0,0,W)
    return vis[0][0][0]
print( solve() )