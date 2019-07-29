"""
ID: brokard1
LANG: PYTHON3
TASK: milk2
"""
fin = open('milk2.in','r')
fout = open('milk2.out','w')
list = fin.readlines()
N = int(list[0].split()[0])
start = []
end = []
##########################
#### CREATE START AND END LISTS INSTEAD OF USING .SPLIT() A BUNCH OF TIMES
for j in range(1,N+1):
    start.append(int(list[j].split()[0]))
    end.append(int(list[j].split()[1]))
t = min(start)
T = max(end)
def milked(t):
    max = 0
    for j in range(N):
        if start[j] < t and t <= end[j]:
            if max < end[j]:
                max = end[j]
    if max == 0:
        return (False,0)
    return (True,max)
def lower_bound(t):
    min = T-1
    for j in range(N):
        if t <= start[j] and start[j] <= min:
            min = start[j]
    return min+1
maxMilk = 0
contMilk = 0
maxNot = 0
contNot = 0
t+=1
while t <= T:
    if milked(t)[0]==True:
        while milked(t)[0]==True:
            contMilk += (milked(t)[1]-t+1)
            t = (milked(t)[1]+1)
        if maxMilk < contMilk:
            maxMilk = contMilk
        contMilk = 0
    else:
        while milked(t)[0] == False:
            contNot += (lower_bound(t)-t)
            #contNot += 1
            #t+= 1
            t = lower_bound(t)
        if maxNot < contNot:
            maxNot = contNot
        contNot = 0
fout.write(str(maxMilk) + ' ' + str(maxNot)+'\n')
