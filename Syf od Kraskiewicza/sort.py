
dane = [ "alicja" ,"arek" ,"ola" ,"olek", "ala"]

#rozwiazanie ala alicja arek ola olek

def findMax(tab):
    max = -1
    for i in range(len(tab)):
        if max < len(tab[i]):
            max = len(tab[i])
    
    return max

def sort(tab):
    max = findMax(tab) - 1
    while max >= 0:
        zlicz = []    
        for i in range(27):
            zlicz.append([])
        
        for i in range(0, len(tab)):
            if(len(tab[i]) - 1 >= max):
                zlicz[ord(tab[i][max]) - 97].append(tab[i])
            else:
                zlicz[26].append(tab[i])
        newTab = []

        while zlicz[26]:
            newTab.append(zlicz[26].pop())

        for i in range(26):
            zlicz[i].reverse()
            while zlicz[i]:
                newTab.append(zlicz[i].pop())
        tab = newTab.copy()
        max -= 1
    return tab

print(sort(dane))