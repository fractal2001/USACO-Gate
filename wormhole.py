"""
ID: brokard1
LANG: PYTHON3
TASK: wormhole
"""
fin = open('wormhole.in','r')
fout = open('wormhole.out','w')
list = fin.readlines()
N = int(list[0].split()[0])
wormholes = []
for i in range(1,N+1):
    wormholes.append((int(list[i].split()[0]),int(list[i].split()[1])))
def enum(wormholes):
    ## enumerates all possible graphs in form of a dictionary. Perfect
    if len(wormholes) == 2:
        return [{wormholes[0]:wormholes[1], wormholes[1]:wormholes[0]}]
    listDict = []
    seed = wormholes[0]
    for j in range(1,len(wormholes)):
        inky = wormholes[:]
        dict = {}
        dict[seed] = inky[j]
        dict[inky[j]] = seed
        del inky[j]
        del inky[0]
        for map in enum(inky):
            listDict.append({**dict,**map})
    return listDict
def safe(pos):
    ## Checks if there is a wormhole in Bessie's path
    for point in wormholes:
        if point[0] > pos[0] and point[1] == pos[1]:
            return False
    return True
def closest_hole(pos):
    ## Assuming Bessie is not at a safe position
    ## finds the closest wormhole to her
    ## that she can enter
    check = []
    for point in wormholes:
        if point[0] > pos[0] and point[1] == pos[1]:
            check.append(point)
    min = 0
    for i in range(len(check)):
        if check[min][0] > check[i][0]:
            min = i
    return check[min]
map = enum(wormholes)
count = 0
for graph in map:
    for start in wormholes:
        pos = graph[start]
        pathWorm = [start] ##paths that have position go thru a wormholes
        pathTrav = [pos] ## paths that have a position determined by the closest wormhole
        toggle = False
        while True:
            if not safe(pos):
                pos = closest_hole(pos)
                pathWorm.append(pos)
                pos = graph[pos]
                pathTrav.append(pos)
                if len(set(pathTrav)) != len(pathTrav) or len(set(pathWorm)) != len(pathWorm):
                    count += 1
                    toggle = True
                    break
            else:
                break
        if toggle == True:
            break
fout.write(str(count)+'\n')
