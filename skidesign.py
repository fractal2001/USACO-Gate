"""
ID: brokard1
LANG: PYTHON3
TASK: skidesign
"""
fin = open('skidesign.in','r')
fout = open('skidesign.out','w')
list = fin.readlines()
N = int(list[0].split()[0])
nums = [int(list[i]) for i in range(1,N+1)]
nums.sort()
validIntervals = []
for i in range(nums[0],nums[N-1]-16):
    validIntervals.append((i,i+17))
def fit_into_interval(nums,interval):
    cost = 0
    for val in nums:
        if val < interval[0]:
            cost += (interval[0]-val)**2
        elif val > interval[1]:
            cost += (interval[1]-val)**2
    return cost
costs = []
for x in validIntervals:
    costs.append(fit_into_interval(nums,x))
fout.write(str(min(costs))+'\n')
