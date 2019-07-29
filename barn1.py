"""
ID: brokard1
LANG: PYTHON3
TASK: barn1
"""
fin = open('barn1.in','r')
fout = open('barn1.out','w')
list = fin.readlines()
M = int(list[0].split()[0])
S = int(list[0].split()[1])
C = int(list[0].split()[2])
cows = []
for i in range(1,C+1):
    cows.append(int(list[i].split()[0]))
cows.sort()
differences = []
for i in range(C-1):
    differences.append(cows[i+1]-cows[i]-1)
for i in range(M-1):
    if len(differences) != 0:
        val = max(differences)
        differences.remove(val)
fout.write(str(sum(differences)+C)+'\n')
