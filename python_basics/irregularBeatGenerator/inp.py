# used in irregular_beat_generator.py
# Most functions have a variable called 'enable_comments'
#   -> setting this variable to True gives an insight in what's going on inside each function

class color:
    GRAY = '\x1b[90m'
    REDB = '\x1b[91m'
    GREENB = '\x1b[92m'
    YELLOWB = '\x1b[93m'
    BLUEB = '\x1b[94m'
    MAGENTAB = '\x1b[95m'
    CYANB = '\x1b[96m'
    WHITEB = '\x1b[97m'
    RED = '\x1b[31m'
    GREEN = '\x1b[32m'
    YELLOW = '\x1b[33m'
    BLUE = '\x1b[34m'
    MAGENTA = '\x1b[35m'
    CYAN = '\x1b[36m'
    WHITE = '\x1b[37m'
    RESET = '\x1b[0m'

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

    # Dictionary containing value_types that input_value can be casted to
    cast = {"int":int, "float":float, "string":str}

    try:
        casted_value = cast[type](input_value) # If unable to run it will skip the 'return casted_value' and run the code after except:
        return casted_value
    except:
        return validateType(input(f"Doesn't understand '{input_value}', expected {type}, try again: "), type)

def constrain(value, minimum, maximum):
    """ Constrains value between minimum and maximum """

    constrained_value = min(maximum, max(minimum, value))
    if value != constrained_value:
        print(f'\n{color.YELLOWB}Value is out of bounds{color.RESET}, returning {constrained_value}\n')
    return constrained_value

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

def rotate(input_list,amount): #input_list[
    """ Rotates input_list


    Parameter input_list: list to rotate
    parameter amount: amount to rotate list

    =======================================

    Scenario with only one note:
        -> index 0 with duration 4 so check first four durations if they are the same as index 0.
            -> If they are, duration isn't split between first and last index (all values are next together in list)
            -> If they are not, duration is split
                -> count all values that != index 0
                -> the amount of values that != index 0 = rest_duration
        -> BUT value IS split between first and last index, it is not detected because there is only one value:
            -> 0 == 0 == 0 == 0 -> rest value = 0

    Fix with enumerate if len(input_list) == 0:
        -> enumerate(index_list) = [(1,0),(2,0),(3,0),(4,0)]
        -> with rotate = 2 (right) returns [(3,0),(4,0),(1,0),(2,0)]    *not a list at first but an enumerate object
        -> get index of index, i in <rotated_enumerated_index_list>]
            -> [index for index, (i,j) in enumerate(rotated_enumerated_index_list) if i == 1][0]      *[0] to remove [] brackets
                -> result = 3
                    -> rest_duration = result-1
    """

    enable_comments = False

    index_list = []

    toggle_print('\n======[Durations -> Indexes]======',enable_comments)

    for index, i in enumerate(input_list):
        for j in range(i):
            index_list.append(index)
            toggle_print('\nlist:', input_list,enable_comments)
            toggle_print('times:', i, '\nindex:', index,enable_comments)
            toggle_print('index_list:',index_list,enable_comments)

    toggle_print('\nresult --> index_list:',index_list,enable_comments)

    toggle_print('\n============[Rotation]============',enable_comments)

    toggle_print('\namount:',amount,enable_comments)
    wrapped_amt = abs(amount) % len(index_list)
    toggle_print('amount_wrapped',wrapped_amt,enable_comments)

    # Nested function whatt
    def rotate_indexes(inp_list):
        if amount >0:      # rotate_right
            return inp_list[-wrapped_amt:] + inp_list[:-wrapped_amt]
        elif amount <0:    # rotate_left
            return inp_list[wrapped_amt:]+inp_list[:wrapped_amt]
        else:
            return inp_list

    rotated_indexes = rotate_indexes(index_list)

    toggle_print('result --> rotated_indexes:', rotated_indexes,enable_comments)

    toggle_print('\n=========[Calculate Rest]=========',enable_comments)

    rotated_list = []
    append_value = 0
    rest_duration = 0

    for index, i in enumerate(rotated_indexes):

        duration_at_index = input_list[i]
        if index == 0:

            if duration_at_index > 1:

                if len(input_list) == 1:
                    toggle_print('\nlength of list is 1...\nuse alternate method for determining rest_duration',enable_comments)
                    enumerated_rotated_indexes = rotate_indexes(list(enumerate(index_list)))
                    toggle_print(f'\nenumerate index_list: {list(enumerate(index_list))}\nand rotate: {enumerated_rotated_indexes}',enable_comments)
                    rest_duration = [index for index, (i,j) in enumerate(enumerated_rotated_indexes) if i == 0][0]

                else:
                    toggle_print('\nduration of index[0] is at least 2',enable_comments)

                    # Ceck if duration at index[0] is split between last and first index because of the rotation
                    toggle_print('same number?:', rotated_indexes[:duration_at_index],enable_comments)
                    for j in rotated_indexes[:duration_at_index]:

                        # Add 1 to rest_duration for every pulse that's at the beginning of the sequence instead of at the end
                        if(j != i):
                            toggle_print(j,'is not same number, add 1 to rest duration',enable_comments)
                            rest_duration += 1
                        else:
                            toggle_print(j,'is same number',enable_comments)

                    toggle_print('result --> rest_duration:', rest_duration, '\n\n======[Indexes -> Durations]======\n',enable_comments)

            if rest_duration == 0:
                rotated_list.append(input_list[rotated_indexes[0]])
                toggle_print(i,'append_value:', input_list[rotated_indexes[0]], '\nrotated_list:',rotated_list, '\n',enable_comments)

        if i != rotated_indexes[0]:
            if append_value < duration_at_index:
                append_value += 1
                if append_value == duration_at_index:
                    rotated_list.append(append_value)
                    toggle_print(i,'append_value:',append_value,enable_comments)
                    toggle_print('rotated_list:',rotated_list, '\n',enable_comments)
                    append_value = 0
                else:
                    continue
        else:
            continue
    else:
        if rest_duration != 0:
            rotated_list.append(input_list[rotated_indexes[0]]-rest_duration) # If you want to stop the note at the end of the cycle
            # rotated_list.append(input_list[rotated_indexes[0]])               if you want the note to continue after the cycle has ended
        toggle_print("stored recombined indexes in 'rotated_list' \n\nresult --> rotated_list:", rotated_list, '\nresult --> rest_duration:', rest_duration,'\n',enable_comments)
        return (rotated_list, rest_duration)
