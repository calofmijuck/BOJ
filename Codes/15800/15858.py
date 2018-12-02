from decimal import *
getcontext().prec = 40
a, b, c = [int(e) for e in input().split()]
print(Decimal(a * b) / Decimal(c))
