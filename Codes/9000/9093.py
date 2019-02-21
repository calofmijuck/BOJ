n = int(input())
for i in range(n):
    print(" ".join([e[::-1] for e in input().split()]))
