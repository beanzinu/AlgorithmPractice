def solution(n):
    answer = 0
    begin,end = 1,2
    while begin < end:
        num_sum = sum(range(begin,end+1))
        if num_sum < n:
            end += 1
        elif num_sum == n:
            answer += 1
            begin += 1
        else:
            begin += 1
    return answer+1