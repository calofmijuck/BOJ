import os
from termcolor import colored

global perLine
perLine = 20

def parse(filename):
    ret = filename.split(".")[0]
    ret = ret.split("-")[0]
    ret = ret.split("_")[0]
    if ret.isdigit():
        return int(ret)
    else:
        raise Exception

def prettyprint(sList, pList):
    green, red = 0, 0
    li = []
    for i in range(len(sList)):
        if sList[i] in pList:
            print(colored(str(sList[i]), 'green'), end="\t")
            green += 1
            li.append(sList[i])
        else:
            print(colored(str(sList[i]), 'red'), end="\t")
            red += 1
        if (i + 1) % perLine == 0:
            print("")
    print("")
    return li

def solved(filename):
    solvedList = []
    f = open(filename, "r")
    for line in f:
        for e in line.split(" "):
            solvedList.append(int(e))
    solvedList.sort()
    return solvedList


def getProbList(dir):
    probList = set()
    for root, dirs, files in os.walk(dir, topdown = True):
        for name in files:
            try:
                probList.add(parse(name))
            except Exception as e:
                pass
    probList = list(probList)
    probList.sort()
    return probList


# Pass the filename that contains solved problems
solvedList = solved("./solved")
<<<<<<< HEAD

# Pass the directory that contains the solution codes
probList = getProbList("./Codes")

=======
probList = getProbList("./Codes")

>>>>>>> 7b3913daf40906c356dd6b6d49ad7f9d9bbfd1e3
li = prettyprint(solvedList, probList)
assert li == probList
print("Total No. of Problems: %d" % len(solvedList))
print("Existing No. of Problems: %d" % len(probList))
print("Needs to be updated: %d" % (len(solvedList) - len(probList)))
