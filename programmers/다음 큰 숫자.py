def solution(n):
    one_in_n = format(n,"b").count("1")
    m = n+1

    while 1:
        if one_in_n == format(m,"b").count("1"):
            return m
        m += 1