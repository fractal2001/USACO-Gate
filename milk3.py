"""
ID: brokard1
LANG: PYTHON3
TASK: milk3
"""
fin = open('milk3.in','r')
fout = open('milk3.out','w')
list = fin.readlines()
A = int(list[0].split()[0])
B = int(list[0].split()[1])
C = int(list[0].split()[2])
milk = [0,0,C]
cap = [A,B,C]
def pour(x,y,milk):
    if cap[y] >= milk[y] + milk[x]:
        milk[y] += milk[x]
        milk[x] = 0
        return milk
    milk[x] -= (cap[y]-milk[y])
    milk[y] = cap[y]
    return milk
def states_by_pours(milk,depth):
    if depth == 1:
        a = pour(2,0,milk)
        milk = [0,0,C]
        b = pour(2,1,milk)
        milk = [0,0,C]
        return [a,b]
    else:
        out = []
        for state in states_by_pours(milk,depth-1):
            absState = state[:]
            a = pour(2,0,absState)
            absState = state[:]
            b = pour(2,1,absState)
            absState = state[:]
            c = pour(1,0,absState)
            absState = state[:]
            d = pour(1,2,absState)
            absState = state[:]
            e = pour(0,2,absState)
            absState = state[:]
            f = pour(0,1,absState)
            absState = state[:]
            for x in [a,b,c,d,e,f]:
                if x not in out:
                    out.append(x)
        return out

i = 1
while len(states_by_pours(milk,i)) < len(states_by_pours(milk,i+1)):
    i+= 1
Qs = states_by_pours(milk,i)
poss_A = []
for x in Qs:
    if (x[0] == 0) and (x[2] not in poss_A):
        poss_A.append(x[2])
poss_A.sort()
for i in range(len(poss_A)-1):
    fout.write(str(poss_A[i])+' ')
fout.write(str(poss_A[-1])+'\n')
