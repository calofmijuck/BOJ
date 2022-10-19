END_OF_INPUT = [0, 0]

while True:
    start, duration = [[int(x) for x in e.split(":")] for e in input().split()]

    if start == END_OF_INPUT and duration == END_OF_INPUT:
        break

    end = [start[i] + duration[i] for i in range(2)]

    if end[1] // 60 > 0:
        end[0] += end[1] // 60
        end[1] %= 60

    days = 0
    if end[0] >= 24:
        days = end[0] // 24
        end[0] %= 24

    result = f"{end[0]:02}:{end[1]:02}"
    if days > 0:
        result += f" +{days}"
    print(result)
