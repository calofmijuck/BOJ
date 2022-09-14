string = input().lower()

result = "unrated" if string.find("d2") == -1 else "D2"
print(result)
