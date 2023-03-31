weights = [2, 7, 6, 5, 4, 3, 2]
letter = {
    0: "J",
    1: "A",
    2: "B",
    3: "C",
    4: "D",
    5: "E",
    6: "F",
    7: "G",
    8: "H",
    9: "I",
    10: "Z",
}

digits = input()

sum = 0
for idx, d in enumerate(digits):
    sum += weights[idx] * int(d)

r = sum % 11

print(letter[r])
