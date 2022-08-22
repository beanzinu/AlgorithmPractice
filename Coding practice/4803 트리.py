import sys
from collections import Counter
input = sys.stdin.readline


case = 0
while True:
    case += 1
    n,m = map(int,input().split(" "))
    if n==0 and m==0:
        break

    edges = [ [] for _ in range(n+1) ]
    visited = [ 0 for _ in range(n+1) ]
    answer = 0

    for _ in range(m):
        a,b = map(int,input().split(" "))
        edges[a].append(b)
        edges[b].append(a)


    def dfs(prev_node,node,visited):
        visited[node] = 1
        for next_node in edges[node]:
            if prev_node == next_node:
                continue
            if visited[next_node] or not dfs(node,next_node,visited): # 이미 방문했을 경우 사이클 존재
                return False
        return True

    for i in range(1,n+1):
        if visited[i]==0 and dfs(-1,i,visited):
            answer += 1

    print_trees = { 0: "No trees." , 1: "There is one tree."}
    if answer > 1:
        print( f"Case {case}: A forest of {answer} trees.")
    else:
        print( f"Case {case}:",print_trees[answer])
        

    # parent = [ i for i in range(n+1) ]
    # cycle = []
    # for _ in range(m):
    #     a,b = map(int,input().split(" "))
    #     if parent[a]==parent[b]: # 사이클 존재
    #         cycle.append(parent[a])
    #     else: # parent[a] =! a or parent[b] != b
    #         if parent[a] in cycle or parent[b] in cycle:
    #             cycle.append(parent[a])
    #             cycle.append(parent[b])
    #         other_parent = parent[b]
    #         for i in range(len(parent)):
    #             if parent[i] == other_parent:
    #                 parent[i] = parent[a]

    # answer = 0
    # for num,cnt in Counter(parent).most_common():
    #     if num != 0 and num not in cycle:
    #         answer += 1

    

