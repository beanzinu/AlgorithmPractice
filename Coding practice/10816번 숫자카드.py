import sys
from collections import defaultdict
input = sys.stdin.readline
N = int(input())
cards = list(map(int,input().split(" ")))
M = int(input())
numbers = list(map(int,input().split(" ")))
d = defaultdict(int)


for card in cards:
    d[card] += 1

for number in numbers:
    if number in d:
        print(d[number],end=" ")
    else:
        print(0,end=" ")
