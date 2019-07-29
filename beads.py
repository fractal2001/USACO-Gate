"""
ID: brokard1
LANG: PYTHON3
TASK: beads
"""
fin = open('beads.in','r')
fout = open('beads.out','w')
list = fin.readlines()
length = int(list[0].split()[0])
necklace = list[1].split()[0]
possible = []
for j in range(0,length):
    possible.append(necklace[j:]+necklace[:j])
def ideals(string):
    unknown = ''
    for x in string:
        if x not in unknown:
            unknown += x
    return unknown
def get_left_beads(string):
    k=1
    while len(ideals(string[:k]))<=2 and (ideals(string[:k]) not in ['rb','br']):
        if k > len(string):
            break
        k+=1
    return k-1
def reverse(s):
    if len(s) == 0:
        return s
    else:
        return reverse(s[1:]) + s[0]
def get_right_beads(string):
    string = reverse(string)
    return get_left_beads(string)
max = 0
for string in possible:
    if (get_left_beads(string) + get_right_beads(string)) > max:
        max = get_left_beads(string) + get_right_beads(string)
if max > length:
    fout.write(str(length)+'\n')
else:
    fout.write(str(max)+'\n')
