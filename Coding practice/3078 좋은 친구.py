import sys
from collections import defaultdict
input = sys.stdin.readline

N,K = map(int,input().split())

friends = []
name_lengths = defaultdict(int)
for i in range(N):
    s = input()[:-1]
    if i < K:
        name_lengths[len(s)] += 1
    friends.append(s)

ans = 0
index = K
# O(N)
for friend in friends:
    current_length = len(friend)
    # 자신은 제외 : O(|S|)
    name_lengths[current_length] -= 1
    # 자신+K번째 친구 추가 : O(|S|)
    if index < len(friends):
        name_lengths[len(friends[index])] += 1
    index += 1
    # 자신과 같은 길이의 친구들 정답에 추가 : O(|S|)
    ans += name_lengths[current_length]

print(ans)

