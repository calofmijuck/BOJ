emoji = input()

difficulty = len(emoji) + emoji.count(':') + emoji.count('_') * 5
print(difficulty)
