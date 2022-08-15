import sys
from collections import defaultdict
input = sys.stdin.readline

N = int(input())
balls = list(map(int,input().split(" ")))
M = int(input())
numbers = list(map(int,input().split(" ")))

d = defaultdict(set)
d[0].add(balls[0])
d[0].add(0)
d[0].add(-balls[0])
for i in range(1,N):
    if i-1 in d:
       for num in d[i-1]:
           d[i].add(num+balls[i])
           d[i].add(num)
           d[i].add(num-balls[i]) 

for number in numbers:
    print( "Y" if number in d[N-1] else "N" ,end=" ")

