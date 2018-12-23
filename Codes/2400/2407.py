import math
n, m = [int(e) for e in input().split()]
m = min(m, n - m)
res = 1
for i in range(1, m + 1):
    res = res * (n + 1 - i) // i;
print(res)
