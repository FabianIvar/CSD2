def check(inp,type):
        match type:
            case 'int':
                try:
                    int(inp)
                except ValueError:
                    return check(input("Must be an integer, try again: "), 'int')
                except TypeError:
                    return check(inp,'other')
                else:
                    return int(inp)
            case 'float':
                try:
                    float(inp)
                except ValueError:
                    return check(input("Must be a float, try again: "), 'float')
                except TypeError:
                    return check(inp,'other')
                else:
                    return float(inp)
            case 'float_int':
                try:
                    float(inp)
                except ValueError:
                    return check(input("Must be a float or int, try again: "), 'float_int')
                except TypeError:
                    return check(inp,'other')
                else:
                    return float(inp)
            case 'other' | _:
                try:
                    int(inp[0])
                except ValueError:
                    try:
                        float(inp[0])
                    except ValueError:
                        return input("doesn't understand " + inp + ", try again: ")
                    else:
                        return float(inp[0])
                except TypeError:
                    return input("doesn't understand ", inp[0], ", try again: ")
                else:
                    return int(inp[0])

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
