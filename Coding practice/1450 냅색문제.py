import sys
input = sys.stdin.readline

n,c = map(int,input().split(" "))
weights = list(map(int,input().split(" ")))

weights.sort()

def find(start,end,total,v):
    if total > c:
        return
    if start == end:
        if total:
            v.append(total)
        return
    find(start+1,end,total+weights[start],v)
    find(start+1,end,total,v)


l,r = [0],[0]
find(0,n//2,0,l)
find(n//2,n,0,r)


answer = 0
r.sort()
rr = len(r)
for le in l:
    dif = c - le
    start,end = 0,rr
    while start<end:
        mid = (start+end)//2
        if r[mid] > dif:
            end = mid
        else:
            start = mid+1
    answer += end

print(answer)
