from collections import defaultdict
def solution(dirs):
    answer = 0
    d = defaultdict(list)
    move = { "L" : (-1,0) , "R" : (1,0) , "U" : (0,1) , "D" : (0,-1)}
    reverse = { "L" : "R" , "R" : "L" , "U" : "D" , "D" : "U"}
    
    x,y = 0,0
    for direction in dirs:
        key = str(x)+str(y)
        next_x,next_y = x+move[direction][0],y+move[direction][1]
        if (-5<=next_x<=5) and (-5<=next_y<=5):
            x,y = next_x,next_y
            if direction not in d[key]:
                new_key = str(x)+str(y)
                d[key].append(direction)
                d[new_key].append(reverse[direction]) # 역방향
                answer += 1

    return answer