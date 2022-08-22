import sys
input = sys.stdin.readline

n = int(input())
def makePrime(num):
    d = [ i for i in range(n+1) ]
    prime = []
    
    for i in range(2,n+1):
        if d[i]==0:
            continue
        j = i*2
        prime.append(i)
        while j <= n:
            d[j] = 0
            j += i 
    return prime

p = makePrime(n)   
start,end = 0,0
num_sum = p[0] if p else 0
answer = 0

while end < len(p):
    if num_sum == n:
        answer += 1
    if num_sum >= n:
        num_sum -= p[start]
        start += 1
    else:
        end += 1
        num_sum += p[end] if end < len(p) else 0
print(answer)