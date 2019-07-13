exp = input().split("-")
for i in range(len(exp)):
        tmp = [str(int(e)) for e in exp[i].split('+')]
        exp[i] = eval("+".join(tmp))
ans = exp[0]
for i in range(1, len(exp)):
        ans -= exp[i]
print(ans)
