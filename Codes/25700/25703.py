n = int(input())
print("int a;\nint *ptr = &a;")

for i in range(1, n):
    print(f"int {'*' * (i+1)}ptr{i+1} = &ptr{'' if i == 1 else i};")
