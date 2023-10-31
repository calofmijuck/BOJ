table = {}

def exponentiate(a : int, b : int, m : int) -> int:
    if b == 0:
        return 2 % m
    if b == 1:
        return a % m

    if b in table.keys():
        return table[b]

    result = 0
    if b % 2 == 0:
        t = exponentiate(a, b // 2, m)
        result = (t * t - 2 + m) % m
    else:
        t1 = exponentiate(a, b // 2 + 1, m)
        t2 = exponentiate(a, b // 2, m)
        result = (t1 * t2 - a + m) % m

    table[b] = result
    return result

a, b, m = [int(e) for e in input().split()]

print(exponentiate(a, b, m))
