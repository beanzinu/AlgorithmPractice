from collections import defaultdict
def solution(lines):
    d = defaultdict(list)
    for line in lines:
        p1,p2 = line[0],line[1]
        d[p1].append(p2)
    
    for first in d:
        result = 0
        for second in d[first]:
            result += 10
            if second in d:
                for third in d[second]:
                    result += 3
                    if third in d:
                        for fourth in d[third]:
                            result += 1
        print(result)
solution([[1,2],[1,3],[2,4],[2,5],[3,6],[4,7],[4,8]])