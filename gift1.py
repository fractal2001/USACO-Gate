"""
ID: brokard1
LANG: PYTHON3
TASK: gift1
"""
fin = open('gift1.in','r')
fout = open('gift1.out','w')
list = fin.readlines()
NP = int(list[0])
values = {}
for i in range(1,NP+1):
    values[list[i].rstrip()]=0
def transfer(person,money,people):
    amt = 0
    if len(people) !=0:
        amt = money//len(people)
    values[person] -= money
    values[person] += (money-(amt*len(people)))
    for person in people:
        values[person] += amt
def check_int(list):
    for x in list:
        try:
            int(x)
        except ValueError:
            return False
    return True
j = NP+1
while j < len(list):
    if check_int(list[j].split()):
        person = list[j-1].rstrip()
        money = int(list[j].split()[0])
        nppl = int(list[j].split()[1])
        recv = []
        for k in range(1,nppl+1):
            recv.append(list[j+k].rstrip())
        transfer(person,money,recv)
    j += 1
for x in values.keys():
    fout.write(x + ' ' + str(values[x])+'\n')
