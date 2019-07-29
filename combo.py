"""
ID: brokard1
LANG: PYTHON3
TASK: combo
"""
fin = open('combo.in','r')
fout = open('combo.out','w')
list = fin.readlines()
N=int(list[0].split()[0])
def close(a,b):
    return (abs(a-b) <= 2 or abs(abs(a-b)-N) <= 2)
def enlist(num):
    list = []
    for i in range(1,N+1):
        if close(i,num):
            list.append(tuple([i]))
    return list
def enum(comb):
    if len(comb) == 1:
        return enlist(int(comb[0]))
    first = enlist(comb[0])
    del comb[0]
    x = enum(comb)
    newList = []
    for elem in first:
        for val in x:
            newList.append(elem + val)
    return newList
fj = [int(x) for x in list[1].split()]
master = [int(x) for x in list[2].split()]
tot = enum(master) + enum(fj)
fout.write(str(len({*tot}))+'\n')
