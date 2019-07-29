"""
ID: brokard1
LANG: PYTHON3
TASK: palsquare
"""
import math
fin = open('palsquare.in','r')
fout = open('palsquare.out','w')
B = int(fin.readlines()[0].split()[0])
def to_B(num):
    place = int(math.log(num,B))
    digits = []
    j = place
    while j >= 0:
        digits.append(num//(B**j))
        num = num-((num//(B**j)) * (B**j))
        j -= 1
    ans = ''
    for x in digits:
        if x <= 9:
            ans += str(x)
        else:
            ans += chr(87+x).capitalize()
    return ans
valid = []
for N in range(1,301):
    if to_B(N**2) == to_B(N**2)[::-1]:
        fout.write(str(to_B(N))+' '+str(to_B(N**2))+'\n')
