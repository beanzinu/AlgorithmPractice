import sys
input = sys.stdin.readline

n = int(input())
p = []
for _ in range(n):
    p.append( list(map(int,input().split())) )

p1 = (p[0][0],p[0][1])

answer = 0
for i in range(1,n-1):
    p2 = (p[i][0],p[i][1])
    p3 = (p[i+1][0],p[i+1][1])

    answer += ((p2[0]-p1[0])*(p3[1]-p1[1]) - (p2[1]-p1[1])*(p3[0]-p1[0]))/2


print( round(abs(answer),2) )