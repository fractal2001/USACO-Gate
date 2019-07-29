"""
ID: brokard1
LANG: PYTHON3
TASK: crypt1
"""
fin = open('crypt1.in','r')
fout = open('crypt1.out','w')
list = fin.readlines()
N = int(list[0].split()[0])
numbers = [int(x) for x in list[1].split()]
def depth(k):
    if k==1:
        return numbers
    else:
        list = []
        prev = depth(k-1)
        for x in numbers:
            for j in prev:
                num = str(x)+str(j)
                list.append(int(num))
        return list
def decompose(num):
    string = str(num)
    return [int(y) for y in string]
first = depth(3)
sec = depth(2)
count = 0
for num1 in first:
    for num2 in sec:
        if num1 * num2 < 10**4 and (num2//10)*num1 < 10**3 and (num2 - (num2//10)*10)*num1 < 10**3 and (num2 - (num2//10)*10)*num1 >= 10**2 and (num2//10)*num1 >= 10**2:
            if set(decompose(num1 * num2)).issubset(set(numbers)) and set(decompose((num2 - (num2//10)*10)*num1)).issubset(set(numbers)) and set(decompose((num2//10)*num1)).issubset(set(numbers)):
                count += 1
fout.write(str(count)+'\n')
