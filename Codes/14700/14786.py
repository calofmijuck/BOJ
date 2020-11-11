from decimal import *

getcontext().prec = 150
getcontext().rounding = ROUND_HALF_UP

pi = Decimal("3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128")

def sin(x):
    x %= 2 * pi
    ret = Decimal(x)
    prev_ret = Decimal("0")
    i = Decimal("1")
    fact = Decimal("1")
    sgn = 1
    num = Decimal(x)
    while ret != prev_ret:
        prev_ret = ret
        num *= x * x
        i += 2
        fact *= i * (i - 1)
        sgn *= -1
        ret += sgn * num / fact
    return ret


a, b, c = [Decimal(e) for e in input().split()]
x = Decimal()
left = Decimal("0")
right = Decimal("500000")
ep = Decimal("1.0e-60")

while Decimal(right - left).copy_abs() >= ep:
    x = (left + right) / 2
    if a * x + b * sin(x) < c:
        left = x
    else:
        right = x

print(round(x, 15))