import sys,copy
input = sys.stdin.readline

N = int(input())
arr = []
for _ in range(N):
    arr.append(list(map(int,input().split())))

U,R,D,L = 0,1,2,3

def combine(arr,dir):
    if dir==U:
        for i in range(N):
            for j in range(N):
                if arr[i][j]:
                    # 아래쪽에 나랑 같은 값이 존재하는 지 확인
                    k= i
                    while k+1<N:
                        if arr[k+1][j]:
                            if arr[k+1][j] == arr[i][j]:
                                arr[i][j] *= 2
                                arr[k+1][j] = 0
                                break
                            else:
                                break
                        k += 1
                    if i+1 < N and arr[i][j] == arr[i+1][j]:
                        arr[i][j] *= 2
                        arr[i+1][j] = 0
                    # 빈칸이면 위로 옮기기
                    k = i
                    while k-1>=0 and arr[k-1][j] == 0:
                        arr[k-1][j] = arr[k][j]
                        arr[k][j] = 0
                        k -= 1
    elif dir==D:
        for i in reversed(range(N)):
            for j in range(N):
                if arr[i][j]:
                    # 위쪽에 나랑 같은 값이 존재하는 지 확인
                    k= i
                    while k-1>=0:
                        if arr[k-1][j]:
                            if arr[k-1][j] == arr[i][j]:
                                arr[i][j] *= 2
                                arr[k-1][j] = 0
                                break
                            else:
                                break
                        k -= 1
                    # 빈칸이면 아래로 옮기기
                    k = i
                    while k+1<N and arr[k+1][j] == 0:
                        arr[k+1][j] = arr[k][j]
                        arr[k][j] = 0
                        k += 1
    elif dir==L:
        for j in range(N):
            for i in range(N):
                if arr[i][j]:
                    # 오른쪽에 나랑 같은 값이 존재하는 지 확인
                    k= j
                    while k+1<N:
                        if arr[i][k+1]:
                            if arr[i][k+1] == arr[i][j]:
                                arr[i][j] *= 2
                                arr[i][k+1] = 0
                                break
                            else:
                                break
                        k += 1
                    # 빈칸이면 왼쪽으로 옮기기
                    k = j
                    while k-1>=0 and arr[i][k-1] == 0:
                        arr[i][k-1] = arr[i][k]
                        arr[i][k] = 0
                        k -= 1
    else: # R
        for j in reversed(range(N)):
            for i in range(N):
                if arr[i][j]:
                    # 왼쪽쪽에 나랑 같은 값이 존재하는 지 확인
                    k= j
                    while k-1>=0:
                        if arr[i][k-1]:
                            if arr[i][k-1] == arr[i][j]:
                                arr[i][j] *= 2
                                arr[i][k-1] = 0
                                break
                            else:
                                break
                        k -= 1
                    # 빈칸이면 오른쪽으로 옮기기
                    k = j
                    while k+1 < N and arr[i][k+1] == 0:
                        arr[i][k+1] = arr[i][k]
                        arr[i][k] = 0
                        k += 1 

# 4^5 경우의 수
ans = 2
for i in range(4**5):
    n_arr = copy.deepcopy(arr)
    cur = i
    for _ in range(5):
        dir = cur%4
        cur //= 4
        combine(n_arr,dir)
    ans = max(ans,max(map(max,n_arr)))

print(ans)