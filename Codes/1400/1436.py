n = int(input())
curr = 666
cnt = 0
for i in range(10000000):
    if str(i).find("666") >= 0:
        cnt += 1
    if cnt == n:
        print(i)
        break
