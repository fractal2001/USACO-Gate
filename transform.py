"""
ID: brokard1
LANG: PYTHON3
TASK: transform
"""
fin = open('transform.in','r')
fout = open('transform.out','w')
list = fin.readlines()
N = int(list[0].split()[0])
orig = []
for i in range(1,N+1):
    orig.append(list[i].split()[0])

final = []
for i in range(N+1,2*N+1):
    final.append(list[i].split()[0])
def rotate(matrix):
    N = len(matrix)
    newMatrix = []
    for j in range(N):
        string = ''
        for i in range(N):
            string += matrix[N-i-1][j]
        newMatrix.append(string)
    return newMatrix
def flip(matrix):
    N = len(matrix)
    newMatrix = []
    for j in range(N):
        newMatrix.append(matrix[j][::-1])
    return newMatrix
if rotate(orig)==final:
    fout.write('1\n')
elif rotate(rotate(orig))==final:
    fout.write('2\n')
elif rotate(rotate(rotate(orig)))==final:
    fout.write('3\n')
elif flip(orig)==final:
    fout.write('4\n')
elif rotate(flip(orig))==final or rotate(rotate(flip(orig)))==final or rotate(rotate(rotate(flip(orig))))==final:
    fout.write('5\n')
elif orig == final:
    fout.write('6\n')
else:
    fout.write('7\n')
