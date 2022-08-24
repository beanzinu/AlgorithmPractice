import sys
input = sys.stdin.readline

n,m = map(int,input().split())
map = [ list(map(int,input().split())) for _ in range(n) ] 
map_index = [ [0]*m for _ in range(n) ]
directions = [(-1,0),(1,0),(0,-1),(0,1)]

def mark(i,j,index): # 섬 인덱싱
    map_index[i][j] = index
    for d in directions:
        next_i,next_j = i+d[0],j+d[1]
        if 0<=next_i<n and 0<=next_j<m and map[next_i][next_j] and map_index[next_i][next_j]==0:
            mark(next_i,next_j,index)
    

index = 1
for i in range(n): 
    for j in range(m):
        if map[i][j] and map_index[i][j]==0:
            mark(i,j,index)
            index += 1

def getBridge(i,j): # 현위치에서 가능한 다리
    result = []
    for d in directions:
        next_i,next_j = i+d[0],j+d[1]
        if not (0<=next_i<n and 0<=next_j<m) or map_index[next_i][next_j]==map_index[i][j]:
            continue
        distance = 1
        while (0<=next_i<n and 0<=next_j<m):
            if map_index[next_i][next_j]:
                if distance <= 2:
                    break
                result.append( (distance-1,map_index[i][j],map_index[next_i][next_j]) )
                break
            next_i,next_j = next_i+d[0],next_j+d[1]
            distance += 1
    return result

bridges = []
for i in range(n):
    for j in range(m):
        if map_index[i][j]:
            bridges.extend(getBridge(i,j))


parent = [ i for i in range(index) ]
# solve
def find(x):
    if parent[x]==x:
        return x
    parent[x] = find(parent[x])
    return parent[x]

answer = 0
answer_cnt = 0
for bridge in sorted(bridges):
    c,a,b = bridge[0],find(bridge[1]),find(bridge[2])
    if a==b:
        continue
    else:
        answer_cnt += 1
        parent[b] = a
        answer += c

print( answer if answer_cnt==index-2 else -1 )