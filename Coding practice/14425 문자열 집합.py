import sys
input = sys.stdin.readline

class Node:
    def __init__(self,val=None,next=None):
        self.val = val
        self.next = {}
        self.mark = False

root = Node()
N,M = map(int,input().split())
# insert
for _ in range(N):
    current = root
    s = input()
    for i,ch in enumerate(s):
        if ch not in current.next:
            child = Node(ch)
            current.next[ch] = child
        current = current.next[ch]
        # mark 
        if i == len(s)-1:
            current.mark = True
        

ans = 0
# find
for _ in range(M):
    current = root
    for ch in input():
        if ch not in current.next:
            break
        current = current.next[ch]
        if current.mark:
            ans += 1
print(ans)
