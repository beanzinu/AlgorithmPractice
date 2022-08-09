import sys
input = sys.stdin.readline

N,B = map(int,input().split(" "))
arr = [ list( map(int,input().split(" ")) ) for _ in range(N) ]
unit = [ [1 if i==j else 0 for j in range(N) ] for i in range(N)  ] 

# 두 매트릭스의 곱
def getMultiMatrix(m1,m2):
    n_arr = [ [0]*N for _ in range(N) ]
    for i in range(N):
        for j in range(N):
            sum = 0
            for n in range(N):
                sum += (m1[i][n] * m2[n][j])%1000
            n_arr[i][j] = sum % 1000
    return n_arr


while B:
    if B%2:
        unit = getMultiMatrix(unit,arr)
    arr = getMultiMatrix(arr,arr)
    B //= 2

for i in range(N):
    for j in range(N):
        print(unit[i][j],end=" ")
    print()
        
