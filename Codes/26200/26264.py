n = int(input())
s = input()

big_data = s.count("bigdata")
security = s.count("security")

if big_data > security:
    print("bigdata?")
elif big_data < security:
    print("security!")
else:
    print("bigdata? security!")
