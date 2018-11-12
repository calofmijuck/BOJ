def solve(str):
    if str.find("__") != -1 or str[-1] == '_' or str[0] == '_':
        print("Error!")
        return None
    if str.find("_") != -1:
        if str.lower() != str:
            print("Error!")
            return None
        words = str.split("_")
        print(words[0], end="")
        for word in words[1:]:
            print(word[0].upper() + word[1:], end="")
    else:
        if str[0].lower() != str[0]:
            print("Error!")
            return None
        for letter in str:
            if letter == letter.lower():
                print(letter, end="")
            else:
                print("_" + letter.lower(), end="")

str = input()
solve(str)
