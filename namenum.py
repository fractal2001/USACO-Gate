"""
ID: brokard1
LANG: PYTHON3
TASK: namenum
"""
fin = open('namenum.in','r')
word = open('dict.txt','r')
fout = open('namenum.out','w')
N = int(fin.readlines()[0].split()[0])
list = word.readlines()
words = [x.rstrip() for x in list]
map = {2:'ABC',3:'DEF',4:'GHI',5:'JKL',6:'MNO',7:'PRS',8:'TUV',9:'WXY'}
def viable(num):
    if len(str(num))==1:
        return [map[num][0],map[num][1],map[num][2]]
    else:
        first = int(str(num)[0])
        beg = [map[first][0],map[first][1],map[first][2]]
        small = int(str(num)[1:])
        list = viable(small)
        return [(map[first][0]+x) for x in list]+[(map[first][1]+x) for x in list]+[(map[first][2]+x) for x in list]
names = []
firstLetters = map[int(str(N)[0])]
narrowed = []
for name in words:
    if name[0] in firstLetters and len(str(N))==len(name):
        narrowed.append(name)
for x in viable(N):
    if x in narrowed:
        names.append(x)
if len(names)==0:
    fout.write('NONE\n')
else:
    for x in names:
        fout.write(x+'\n')
