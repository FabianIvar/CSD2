"""
min(a,b) geeft de laagste waarde.
max(c,d) geeft de hoogste waarde.
als max(0, input) -> returned input tenzij input lager is dan 0
min(1, input) -> returned 1 tenzij input lager is dan 1
dusss:
min(maximum, max(minimum, input)) -> dit constrained input tussen minimum en maximum
"""

def constrain(value, minimum, maximum):
    """ Constrains value between minimum and maximum """
    return min(maximum, max(minimum, value))

def rotate(list,amt):
    """ Rotates a list """
    for i in range(constrain(abs(amt),0,abs(amt))):
        if amt <0:
            n=list[0].pop(0) #have to add another forloop later so that multitrack works (replace [0] with [i])
            list.append(n)
        elif amt >0:
            n=list.pop(-1)
            list.insert(0, n)
        else:
            print("something went wrong")
        # print(list)
    return list
