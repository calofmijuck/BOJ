def dedup(line: str) -> str:
    new_str = line[0]
    for c in line:
        if c != new_str[-1]:
            new_str += c

    return new_str


lines = int(input())

for _ in range(lines):
    line = input()
    print(dedup(line))
