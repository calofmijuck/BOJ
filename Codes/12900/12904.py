s = input()
t = input()
while len(s) != len(t):
    if t[-1] == 'B':
        t = t[:-1]
        t = t[::-1]
    else:
        t = t[:-1]
if s == t:
    print("1")
else:
    print("0")
