import sys,heapq
input = sys.stdin.readline

INF = int(1e9)

for _ in range(int(input())): # Test Case
    n,m,t = map(int,input().split(" "))
    s,g,h = map(int,input().split(" "))
    e = [ [ INF for _ in range(n+1) ] for _ in range(n+1) ]
    cand = []
    for _ in range(m): # 양방향 도로
        a,b,d = map(int,input().split(" "))
        e[a][b] = d
        e[b][a] = d
    for _ in range(t): # 목적지 후보
        cand.append(int(input()))

    result = []
    for start in [s,g,h]:
        d = [INF for _ in range(n+1)]
        d[start] = 0
        pq = [(0,start)]
        while pq:
            cost,node = map(int,heapq.heappop(pq))
            for i in range(1,n+1):
                if d[i] > d[node]+e[node][i]:
                    d[i] = d[node]+e[node][i]
                    heapq.heappush(pq,(d[i],i))
        result.append(d)
    
    answer = []
    for c in cand:
        path1 = result[0][g]+e[g][h]+result[2][c]
        path2 = result[0][h]+e[h][g]+result[1][c]
        if path1 == result[0][c] or path2 == result[0][c]:
            answer.append(c)
    for a in sorted(answer):
        print(a,end=" ")
    print()