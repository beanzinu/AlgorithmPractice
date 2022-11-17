import sys
input = sys.stdin.readline

lines = []

N = int(input())

# O(nlogn)
for _ in range(N):
    lines.append(list(map(int,input().split())))

#O(n)
ans = [[lines[0][0],lines[0][1]] ]
for x,y in sorted(lines,key=lambda x:x[0])[1:]:
    # 겹치는 경우
    if x <= ans[-1][1]:
        ans[-1][1] = max(y,ans[-1][1])
    else:
        ans.append([x,y])

print( sum( y-x for x,y in ans ) )    


