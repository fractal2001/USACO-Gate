"""
ID: brokard1
LANG: PYTHON3
TASK: ride
"""
def value(string):
    dict = {' ':1,'\n':1,'A':1,'B':2,'C':3,'D':4,'E':5,'F':6,'G':7,'H':8,'I':9,'J':10,'K':11,'L':12,'M':13,'N':14,'O':15,'P':16,'Q':17,'R':18,'S':19,'T':20,'U':21,'V':22,'W':23,'X':24,'Y':25,'Z':26}
    prod  = 1
    for char in string:
        prod *= dict[char]
    return prod

def cross_check(string1, string2):
    if (value(string1)-value(string2))%47==0:
        return 'GO\n'
    else:
        return 'STAY\n'

fin = open ('ride.in', 'r')
fout = open ('ride.out', 'w')
list = fin.readlines()
fout.write(cross_check(list[0],list[1]))
fout.close()
