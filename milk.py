"""
ID: brokard1
LANG: PYTHON3
TASK: milk
"""
fin = open('milk.in','r')
fout = open('milk.out','w')
list = fin.readlines()
N = int(list[0].split()[0])
M = int(list[0].split()[1])
P = []
A = []
for i in range(1,M+1):
    P.append(int(list[i].split()[0]))
    A.append(int(list[i].split()[1]))
amount = 0
cost = 0
archive = []
while amount < N:
    p = min(P)
    i = P.index(p)
    cost += A[i] * min(P)
    amount += A[i]
    archive.append((p,A[i]))
    P.remove(p)
    del A[i]
if amount == N:
    fout.write(str(cost)+'\n')
else:
    info = archive[-1]
    p = info[0]
    a = info[1]
    over = amount - N
    cost -= over * p
    fout.write(str(cost)+'\n')
