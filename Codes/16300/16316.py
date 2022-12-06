n = int(input())
text = input().split()

for i in range(len(text)):
    if text[i] == "mumble" or int(text[i]) == i + 1:
        continue
    else:
        print("something is fishy")
        break
else:
    print("makes sense")
