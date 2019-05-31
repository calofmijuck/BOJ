poly = input().split('x')

if len(poly) == 1:
    if poly[0] == '0':
        print("W")
    elif poly[0] == '1':
        print("x+W")
    elif poly[0] == '-1':
        print("-x+W")
    else:
        print("{}x+W".format(poly[0]))
else:
    if poly[1] == '+1':
        poly[1] = '+'
    elif poly[1] == '-1':
        poly[1] = '-'
    if poly[1] != '':
        poly[1] += 'x'
    if poly[0] == '2':
        print("xx{}+W".format(poly[1]))
    elif poly[0] == '-2':
        print("-xx{}+W".format(poly[1]))
    else:
        print("{}xx{}+W".format(int(poly[0]) // 2, poly[1]))
