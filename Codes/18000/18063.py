songs, change = [int(e) for e in input().split()]

sum = -change * (songs - 1)
for _ in range(songs):
    minute, second = [int(e) for e in input().split(":")]
    sum += 60 * minute + second

hour = sum // 3600
minute = (sum % 3600) // 60
seconds = sum % 60

print(f"{hour:02}:{minute:02}:{seconds:02}")
