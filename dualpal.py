"""
ID: brokard1
LANG: PYTHON3
TASK: dualpal
"""
import math
fin = open('dualpal.in','r')
fout = open('dualpal.out','w')
list = fin.readlines()
N = int(list[0].split()[0])
S = int(list[0].split()[1])
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
        ans += str(x)
    return ans
nums = []
index = S+1
while len(nums) != N:
    ops = 0
    for B in range(2,11):
        if ops == 2:
            break
        else:
            if to_B(index) == to_B(index)[::-1]:
                ops += 1
    if ops == 2:
        nums.append(index)
    index += 1
for i in range(N):
    fout.write(str(nums[i])+'\n')
