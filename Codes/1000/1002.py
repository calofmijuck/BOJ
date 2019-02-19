def distance(x1, y1, x2, y2):
    return (x1 - x2) ** 2 + (y1 - y2) ** 2

n = int(input())
for i in range(n):
    arr = [int(e) for e in input().split()]
    d = distance(arr[0], arr[1], arr[3], arr[4])
    if d < (arr[2] + arr[5]) ** 2 and d > (arr[2] - arr[5]) ** 2:
        print(2)
    if d > (arr[2] + arr[5]) ** 2 or d < (arr[2] - arr[5]) ** 2:
        print(0)
    if (d == (arr[2] + arr[5]) ** 2 or d == (arr[2] - arr[5]) ** 2) and d != 0:
        print(1)
    if d == 0 and arr[2] == arr[5]:
        print(-1)
