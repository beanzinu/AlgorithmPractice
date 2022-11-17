import sys,copy
input = sys.stdin.readline

N = int(input())
arr = []
for _ in range(N):
    arr.append(list(map(int,input().split())))

def combine(arr,dir):
    # 회전
    for _ in range(dir):
        arr = [[row[i] for row in arr[::-1]] for i in range(len(arr[0]))]
    # 왼쪽으로 합치기
    for i in range(N):
        tmp = [ 0 for _ in range(N) ]
        idx = 0
        for j in range(N):
            if arr[i][j]:
                if tmp[idx]==0:
                    tmp[idx] = arr[i][j]
                elif tmp[idx]==arr[i][j]:
                    tmp[idx] *= 2
                    idx += 1
                else: # tmp[idx] != 0 and tmp[idx] != arr[i][j]
                    idx += 1
                    tmp[idx] = arr[i][j]
        arr[i] = tmp
    return arr

# 4^5 경우의 수
ans = 0
for i in range(4**5):
    n_arr = copy.deepcopy(arr)
    cur = i
    for _ in range(5):
        dir = cur%4
        cur //= 4
        n_arr = combine(n_arr,dir)
    ans = max(ans,max(map(max,n_arr)))

print(ans)