import sys
input = sys.stdin.readline

N = int(input())

if N==1:
    print("4")
else:
    arr = [1,1]
    for i in range(2,N):
        arr.append(arr[i-1]+arr[i-2])
    print( 2*(arr[N-1]+arr[N-2])+2*arr[N-1])
