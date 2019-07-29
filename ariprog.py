"""
ID: brokard1
LANG: PYTHON3
TASK: ariprog
"""
"""
The commented code is faster and found by fluke. Skipping by 12 instead of 4 somehow works. 
"""
# import operator
# fin = open('ariprog.in','r')
# fout = open('ariprog.out','w')
# list = fin.readlines()
# N = int(list[0].split()[0])
# M = int(list[1].split()[0])
# def gen_bisquares(M):
#     cout = []
#     for i in range(0,M+1):
#         for j in range(0,M+1):
#             cout.append(i**2+j**2)
#     return set(cout)
# bisquares = gen_bisquares(M)
# all = []
# if N <= 5:
#     for start in bisquares:
#         for d in range(1,((2*M**2-start))//(N-1)+1):
#             bad = False
#             for j in range(1,N):
#                 if (start + j*d) not in bisquares:
#                     bad = True
#                     break
#             if not bad:
#                 all.append((start,d))
# else:
#     for start in bisquares:
#         for d in range(12,((2*M**2-start))//(N-1)+1,12):
#             bad = False
#             for j in range(1,N):
#                 if (start + j*d) not in bisquares:
#                     bad = True
#                     break
#             if not bad:
#                 all.append((start,d))
# all.sort(key=operator.itemgetter(1))
# for soln in all:
#     fout.write(str(soln[0])+' '+str(soln[1])+'\n')
# if len(all) == 0:
#     fout.write('NONE\n')
import operator
fin = open('ariprog.in','r')
fout = open('ariprog.out','w')
list = fin.readlines()
N = int(list[0].split()[0])
M = int(list[1].split()[0])
def gen_bisquares(M):
    cout = []
    for i in range(0,M+1):
        for j in range(0,M+1):
            cout.append(i**2+j**2)
    return set(cout)
bisquares = gen_bisquares(M)
all = []
if N <= 5:
    for start in bisquares:
        for d in range(1,((2*M**2-start))//(N-1)+1):
            bad = False
            for j in range(1,N):
                if (start + j*d) not in bisquares:
                    bad = True
                    break
            if not bad:
                all.append((start,d))
else:
    for start in bisquares:
        for d in range(4,((2*M**2-start))//(N-1)+1,4):
            bad = False
            for j in range(1,N):
                if (start + j*d) not in bisquares:
                    bad = True
                    break
            if not bad:
                all.append((start,d))
all.sort(key=operator.itemgetter(1))
for soln in all:
    fout.write(str(soln[0])+' '+str(soln[1])+'\n')
if len(all) == 0:
    fout.write('NONE\n')
