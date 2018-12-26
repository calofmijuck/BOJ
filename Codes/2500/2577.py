a = int(input())
b = int(input())
c = int(input())
N = str(a * b * c)

for i in range(0, 10):
    print(N.count(chr(ord('0')+i)))
