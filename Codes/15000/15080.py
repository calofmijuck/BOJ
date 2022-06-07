def to_seconds(hour, minute, second):
    return 3600 * hour + 60 * minute + second

start_hour, start_minute, start_second = [int(e) for e in input().split(" : ")]
end_hour, end_minute, end_second = [int(e) for e in input().split(" : ")]

start_time = to_seconds(start_hour, start_minute, start_second)
end_time = to_seconds(end_hour, end_minute, end_second)

if start_time > end_time:
    end_time += 24 * 3600

print(end_time - start_time)
