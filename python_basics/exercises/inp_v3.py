# used in euclid_deviationFactor.py

""" What is type cast?

A type cast is basically a conversion from one type to another.
It can be implicit (i.e., done automatically by the compiler, perhaps losing info in the process)
or explicit (i.e., specified by the developer in the code).

The space occupied by the types is of secondary importance.
More important is the applicability (and sometimes convenice) of conversion.

Source: https://stackoverflow.com/questions/7558837/what-exactly-is-a-type-cast-in-c-c#7558911

"""

""" if statement with 'not' as constructor, and if statement with a function inside the brackets?

an if statement with a function inside the brackets will run the code if the function returns True,
same goes for if(not <function>):, but here the code will only run if the function returns False

"""

""" What is a class?

Quick test in commandline:
>>> class Myclass:
...     test = 5
...
>>> print(Myclass.test)
5
>>>

Source: https://www.w3schools.com/python/python_classes.asp

"""

# Dictionary containing value_types that input_value can be casted to
cast = {"int":int, "float":float, "string":str}
# int float and str are a classes! cool, don't fully get it yet :)

def sort_by_timestamp(input_list):
    """Sorts by index 0 of list -> for sort function"""
    return input_list[0]

def toggle_print(*arg):
    """A toggleable print,
    if the last argument is not False the function will work as a normal print()
    except that it will not print arg[-1]"""

    if arg[-1] == False:
        return
    else:
        for index, i in enumerate(arg[:-2]):
            if(not isinstance(i,list)):
                print(arg[index], end = ' ')
            else:
                print(i,end=', ')
        else:
            print(arg[-2])

def validateType(input_value, type):
    """
    Tries to cast input_value to type, if succesful return casted_value.
    If input_value can't be casted to type return ask again for user input.

    Parameter input_value:  Value this function tries to cast
    Parameter type:         Type this function tries to cast to

    ===========================================================
    Based off of code from Ciska Vriezenga
    Source: https://github.com/ciskavriezenga/CSD_25-26/blob/main/csd2a/session5/5f_ui_func_type_range.py#L37
    ===========================================================
    """

    try:
        casted_value = cast[type](input_value) # If unable to run it will skip the 'return True' and run the code after except:
        return casted_value
    except:
        return validateType(input("Doesn't understand ", input_value, "expected type:", type, "\ntry again: "))

def constrain(value, minimum, maximum):
    """ Constrains value between minimum and maximum """
    return min(maximum, max(minimum, value))

def combine(*inputs):
    """Combines all inputs into one list"""

    # enable/disable comments for this function
    enable_comments = False

    toggle_print('\ninput is:\n',inputs, '\nType', type(inputs), len(inputs), enable_comments)

    toggle_print('\ncheck if input is a list:\n',inputs[0], '\nType', type(inputs[0]), enable_comments)

    if isinstance(inputs[0],int):
        toggle_print("\ninput is an int and can't be combined:\n\noutput is:\n",inputs[0], enable_comments)
        return list(inputs)

    toggle_print('\ncheck if list in:\n',[[i for i in inputs[j]] for j in range(len(inputs))][0], enable_comments)

    if False in [isinstance(value, list) for value in [[lists
        for lists in inputs[tuple_number]]
            for tuple_number in range(len(inputs))][0]]:

        toggle_print('\nno lists in inputs...\ncheck if inputs are in a tuple:\n',type(inputs),'\n', inputs, enable_comments)
        if isinstance(inputs, tuple):
            inputs = list(inputs)[0]
            toggle_print('\ninput was in tuple,\n remove tuple\n return:', inputs, enable_comments)
            return inputs
        else:
            toggle_print('!!something went wrong!!', enable_comments)
            return inputs

    toggle_print('\nfound at least one list!', enable_comments)

    output = []

    for j in range(len(inputs)):
        for i in inputs[j]:
            output.extend(i)
        toggle_print('\ntemporary output is:\n',type(output),'\n', output, enable_comments)

    toggle_print('\noutput is:\n',type(output),'\n', output, enable_comments)
    return output


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
