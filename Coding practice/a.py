from collections import deque
def solution(cap, n, deliveries, pickups):
    answer = 0
    
    c1 = 0
    ans1 = 0
    for i in range(len(deliveries)-1,-1,-1):
        if deliveries[i]:
            while deliveries[i]:
                if deliveries[i] > c1:
                    add = 0
                    if (deliveries[i]//cap) * cap + c1 >= deliveries[i]:
                        add = deliveries[i]//cap
                    else:
                        add = deliveries[i]//cap + 1
                    c1 += add*cap
                    ans1 += add*(i+1)
                    c1 -= deliveries[i]
                    deliveries[i] = 0
                else:
                    c1 -= deliveries[i]
                    deliveries[i] = 0
    
    c2 = 0
    ans2 = 0
    for i in range(len(pickups)-1,-1,-1):
        if pickups[i]:
            while pickups[i]:
                if pickups[i] > c2:
                    add = 0
                    if (pickups[i]//cap) * cap + c2 >= pickups[i]:
                        add = pickups[i]//cap
                    else:
                        add = pickups[i]//cap + 1
                    c2 += add*cap
                    ans2 += add*(i+1)
                    c2 -= pickups[i]
                    pickups[i] = 0
                else:
                    c2 -= pickups[i]
                    pickups[i] = 0

    return max(ans1,ans2)*2

print( solution(4, 5, [1, 0, 3, 1, 2], [0, 3, 0, 4, 0]))