"""
ID: brokard1
LANG: PYTHON3
TASK: friday
"""
fin = open('friday.in','r')
fout = open('friday.out','w')
list = fin.readlines()
N = int(list[0])
year = 1900
days = 0
lookout = []
freq = {'Sat':0,'Sun':0,'Mon':0,'Tues':0,'Wed':0,'Thurs':0,'Fri':0}
def get_day(num):
    if num %7 == 1:
        freq['Mon'] += 1
    elif num %7 == 2:
        freq['Tues'] += 1
    elif num %7 == 3:
        freq['Wed'] += 1
    elif num %7 == 4:
        freq['Thurs'] += 1
    elif num %7 == 5:
        freq['Fri'] += 1
    elif num %7 == 6:
        freq['Sat'] += 1
    elif num %7 == 0:
        freq['Sun'] += 1
for i in range(N):
    if year % 400 == 0 or (year % 100 !=0 and year % 4==0):
        want = [0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335]
        want = [(x+13+days) for x in want]
        for elem in want:
            lookout.append(elem)
        year += 1
        days += 366
    else:
        want = [0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334]
        want = [(x+13+days) for x in want]
        for elem in want:
            lookout.append(elem)
        days += 365
        year += 1
for elem in lookout:
    get_day(elem)
BigStr = ''
for x in freq.values():
    BigStr += (str(x)+ ' ')
BigStr = BigStr.rstrip()
fout.write(BigStr+'\n')
