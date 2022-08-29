import sys
input = sys.stdin.readline

p1 = list(map(int,input().split()))
p2 = list(map(int,input().split()))
p3 = list(map(int,input().split()))

result = (p2[0]-p1[0])*(p3[1]-p1[1]) - (p2[1]-p1[1])*(p3[0]-p1[0])

print( 1 if result > 0 else -1 if result < 0 else 0)