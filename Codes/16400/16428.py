a, b = [int(e) for e in input().split()]
n = a % b
if n >= 0:
    print(a // b)
    print(n)
else:
    print(a // b + 1)
    print(n + abs(b))
