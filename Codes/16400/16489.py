from math import sqrt
from decimal import *

getcontext().prec = 30
a, b, c = [Decimal(e) for e in input().split()]

S = Decimal(sqrt((a + b + c) * (a + b - c) * (b + c - a) * (c + a - b)))
R = Decimal(a * b * c / S)
r = S / 2 / (a + b + c)
if a == b and b == c:
    d = 0
else:
    d = sqrt(R * R - a * b * c / (a + b + c))
k = sqrt(R * R - a * a / 4) + sqrt(R * R - b * b / 4) + sqrt(R * R - c * c / 4)

print("%.15f\n%.15f\n%.15f\n%.15f\n%.15f" % (S/4, R, r, d, k))
