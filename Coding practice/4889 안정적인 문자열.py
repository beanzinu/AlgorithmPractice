import sys
input = sys.stdin.readline

index = 1
while True:
    s = input()[:-1]
    # break
    if '-' in s: 
        break
    else:
        stack = []
        for ch in s:
            if stack and ch=='}' and stack[-1]=='{':
                stack.pop()
            else:
                stack.append(ch)

        ans = 0
        while stack:
            tmp = ""
            while len(tmp) < 2:
                tmp += stack.pop()
            if tmp in ["{{","}}"]:
                ans += 1
            elif tmp == "{}":
                ans += 2
        print(f"{index}. {ans}")
        index += 1