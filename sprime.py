"""
ID: brokard1
LANG: PYTHON3
TASK: sprime
"""
fin = open('sprime.in','r')
fout = open('sprime.out','w')
info = fin.readlines()
N = int(info[0].split()[0])
def sum_mod3(num):
    string = str(num)
    sum = 0
    for digit in string:
        sum += int(digit)
    return sum % 3
def prime_test(num):
    # num > 7, and not div by 2,3,5
    d = 7
    while d <= num**(0.5):
        print(d)
        if sum_mod3(d) != 0 and num % d == 0:
            return False
        d += 2
    return True
##VERY IMPORTANT! primes = possible primes not actual ones
def prime_search(depth):
    if depth == 1:
        return [2,3,5,7]
    possible = prime_search(depth-1)
    sifted_primes = []
    for curentPrime in possible:
        for i in [1,3,7,9]:
            poss = 10*curentPrime+i
            if sum_mod3(poss) != 0 and prime_test(poss) == True:
                sifted_primes.append(poss)
    return sifted_primes
output = prime_search(N)
print(output)
for x in output:
    fout.write(str(x)+'\n')
