def solution(n, t, m, p):
    answer = ''
    d = { 10:'A',11:'B',12:'C',13:'D',14:'E',15:'F' }
    
    i = 0
    while len(answer) < m*t:
        num = i
        N = ""
        while num > 1:
            N +=  d[num%n] if num%n>=10 else str(num%n)
            num = num//n
        if num or i==0:
            N += str(num)
        answer += N[::-1]
        i += 1
    
    n_answer = ""
    for i,num in enumerate(answer[:m*t]):
        if (i%m)+1 == p:
            n_answer += num
    
    return n_answer