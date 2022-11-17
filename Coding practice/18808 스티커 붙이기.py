import sys
input = sys.stdin.readline

N,M,K = map(int,input().split())
note = [[0]*M for _ in range(N)]

def OOB(i,j):
    return i<0 or i>=N or j<0 or j>=M

def fill(r,c,di,dj,sticker):
    # 채울 수 없다면 : False
    for i in range(r):
        for j in range(c):
            if sticker[i][j] == 1 and note[di+i][dj+j] == 1:
                return False
    # 채울 수 있다면 : True
    for i in range(r):
        for j in range(c):
            if sticker[i][j] == 1:
                note[di+i][dj+j] = 1
    return True

def rotateFill(R,C,sticker):
        # 4번 회전
        for _ in range(4):
            # 들어갈 수 있는 지
            for i in range(N):
                for j in range(M):
                    if not OOB(i+R-1,j+C-1) and fill(R,C,i,j,sticker):
                        return 
            # 못들어가면 회전
            sticker = [[row[i] for row in sticker[::-1]] for i in range(len(sticker[0]))]
            R = len(sticker)
            C = len(sticker[0])

for _ in range(K):
    R,C = map(int,input().split())
    sticker = []
    for _ in range(R):
        sticker.append(list(map(int,input().split())))
    rotateFill(R,C,sticker)

print( sum( n.count(1) for n in note ) )