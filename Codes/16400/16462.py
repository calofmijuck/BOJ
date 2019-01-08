n = int(input())
sum = 0
for i in range(n):
    x = input()
    if(x != '100'):
        x = x.replace('0', '9').replace('6', '9')
    sum += int(x)

print(round(sum / n + 0.001))
