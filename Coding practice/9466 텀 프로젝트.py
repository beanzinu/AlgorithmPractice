import sys
input = sys.stdin.readline

NOT_VISITED = 0
VISITED = 1
IN_CYCLE = 2
OUT_CYCLE = 3

for _ in range(int(input())):
    n = int(input())
    nums = [0] + list(map(int,input().split()))
    state = [ NOT_VISITED for _ in range(n+1) ]

    def BFS(first:int): # 첫시작노드
        current = first
        while True:
            state[current] = VISITED
            current = nums[current]
            # 이미 사이클이거나 사이클이 아닌 경우를 만났을 때 
            # 처음 ~ 만나기 이전 : 모두 OUT_CYCLE
            if state[current] in [IN_CYCLE,OUT_CYCLE]:
                n_current = first
                while state[n_current]==VISITED:
                    state[n_current] = OUT_CYCLE
                    n_current = nums[n_current]
                return
            # 모두 사이클인 경우 : 모두 IN_CYCLE
            if state[current] == VISITED and current==first:
                while state[current]==VISITED:
                    state[current] = IN_CYCLE
                    current = nums[current]
                return
            # 일부가 사이클인 경우 
            # 처음 ~ 사이클 진입 전 : OUT_CYCLE
            # 사이클 진입후 ~ : IN_CYCLE
            if state[current] == VISITED and current != first:
                while state[current]==VISITED:
                    state[current] = IN_CYCLE
                    n_current = nums[current]
                n_current = first
                while state[n_current]==VISITED:
                    state[n_current] = OUT_CYCLE
                    n_current = nums[n_current]
                return
    
    for i in range(1,n+1):
        if state[i] == NOT_VISITED:
            BFS(i)

    print( state.count(OUT_CYCLE) )


