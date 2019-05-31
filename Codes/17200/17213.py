def H(n, m):
    n = n + m - 1;
    k = min(n - m, m)
    ret = 1
    for i in range(n, n - k, -1):
        ret = ret * i // (n - i + 1)
    return ret


n = int(input())
m = int(input())
m -= n
print(H(n, m))
