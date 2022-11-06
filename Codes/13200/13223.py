start = [int(e) for e in input().split(":")]
end = [int(e) for e in input().split(":")]

coefficient = [3600, 60, 1]

start_second = sum([coefficient[i] * start[i] for i in range(3)])
end_second = sum([coefficient[i] * end[i] for i in range(3)])

if start_second >= end_second:
    end_second += 24 * 3600

diff = end_second - start_second
print("{:02d}:{:02d}:{:02d}".format(diff // 3600, (diff % 3600) // 60, diff % 60))
