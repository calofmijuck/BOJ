from datetime import datetime, timedelta

t = int(input())

for _ in range(t):
    year, month = [int(e) for e in input().split()]
    date = datetime.date(year=year, month=month, day=month)
    diff = timedelta(days = month)

    result = date - diff
    print(f"{result.year} {result.month} {result.day}")
