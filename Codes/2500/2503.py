pos = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
data = []
n = int(input())

def check(num):
        for i in range(n):
                currnum = data[i][0]
                strike, ball = 0, 0
                for j in range(3):
                        if num[j] == currnum[j]:
                                strike += 1
                        elif num.find(currnum[j]) > -1:
                                ball += 1
                if (int(data[i][1]), int(data[i][2])) != (strike, ball):
                        return False
        return True

for i in range(n):
        data.append(input().split(" "))
ans = 0

for i in range(1, 10):
        for j in range(1, 10):
                if j == i:
                        continue
                for k in range(1, 10):
                        if k == i or k == j:
                                continue
                        curr = pos[i] + pos[j] + pos[k]
                        if check(curr):
                                ans += 1
print(ans)
