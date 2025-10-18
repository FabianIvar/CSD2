from inp_v2 import constrain

"""     rotation fix:

[2, 2, 2, 2, 2, 1, 1, 1, 1] -> rotation = -1 (left) -> [2, 2, 2, 2, 1, 1, 1, 1, 1] & {'rest_duration': 1}

first index removed and appended 1, also made a dictionary containing 'rest_duration' that, when converted to seconds, is a value that will be added to all timestamps in a layer.

"""

durations = [2, 2, 2, 2, 2, 1, 1, 1, 1]
print('durations:',durations, '\n')

# def rotate_old(list,amt):
#     """ Rotates a list """
#     for i in range(constrain(abs(amt),0,abs(amt))):
#         if amt <0:
#             n=list[0].pop(0)
#             if n > 1:
#                 list.insert(0, n-1)
#                 list[-1] += 1
#             else:
#                 list.append(n)
#         elif amt >0:
#             n=list.pop(-1)
#             if n > 1:
#                 list.append(n-1)
#                 list[0] += 1
#             else:
#                 list.insert(0,n)
#         else:
#             print("something went wrong")
#         print(i,'list',list)
#     return list

# def rotate_interesting(list):
#     pulses = sum(list)
#     notes = len(list)
#     duration = int(pulses/notes) # stepsize
#     print('duration:',duration)
#     remainder = pulses - duration
#     rotated_list = [0]*pulses
#
#     for i in range(0, pulses, 2):
#         rotated_list[i] = 1
#         print('i:',i)

def rotate(list,amount):

    # Create index_list
    index_list = []

    print('\n======[Durations -> Indexes]======')

    for index, i in enumerate(list):
        for j in range(i):
            index_list.append(index)
            print('\nlist:', list)
            print('times:', i, '\nindex:', index)
            print('index_list:',index_list)

    print('\nresult --> index_list:',index_list)

    print('\n============[Rotation]============')

    print('\namount:',amount)
    wrapped_amt = abs(amount) % len(index_list)
    print('amount_wrapped',wrapped_amt)

    if amount >0:      # rotate_right
        rotated_indexes = index_list[-wrapped_amt:] + index_list[:-wrapped_amt]

    elif amount <0:    # rotate_left
        rotated_indexes = index_list[wrapped_amt:]+index_list[:wrapped_amt]

    else:
        rotated_indexes = index_list

    print('result --> rotated_indexes:', rotated_indexes)

    print('\n=========[Calculate Rest]=========')

    rotated_list = []
    append_value = 0
    rest_duration = 0

    for index, i in enumerate(rotated_indexes):

        duration_at_index = list[i]
        if index == 0:
            if duration_at_index > 1:
                print('\nduration at index[0] is at least 2')

                # Ceck if duration at index[0] is split between last and first index because of the rotation
                print('same number?:', rotated_indexes[:duration_at_index])
                for j in rotated_indexes[:duration_at_index]:

                    # Add 1 to rest_duration for every pulse that's at the beginning of the sequence instead of at the end
                    if(j != i):
                        print(j,'is not same number, add 1 to rest duration')
                        rest_duration += 1
                    else:
                        print(j,'is same number')

                print('result --> rest_duration:', rest_duration, '\n\n======[Indexes -> Durations]======\n')

            if rest_duration == 0:
                rotated_list.append(list[rotated_indexes[0]])
                print(i,'append_value:', list[rotated_indexes[0]], '\nrotated_list:',rotated_list, '\n')

        if i != rotated_indexes[0]:
            if append_value < duration_at_index:
                append_value += 1
                if append_value == duration_at_index:
                    rotated_list.append(append_value)
                    print(i,'append_value:',append_value)
                    print('rotated_list:',rotated_list, '\n')
                    append_value = 0
                else:
                    continue
        else:
            continue
    else:
        if rest_duration != 0:
            rotated_list.append(list[rotated_indexes[0]]-rest_duration)

        print("\nstored recombined indexes in 'rotated_list' \n\nresult --> rotated_list:", rotated_list, '\nresult --> rest_duration:', rest_duration,'\n')


    # for index, i in reversed(rotated_indexes):
    #     duration_at_index = sum([1 for j in rotated_indexes if j == i])
    #     for i in range(duration_at_index):


    # rotated_list[value] += 1

rotated_durations = rotate(durations,int(input('rotate: ')))

"""    Pseudo code right left rotation

RIGHT:  [1, 2, 3, 4, 5, 6, 7, 8] -> rotation_amt = 5 (5 to right) -> [4, 5, 6, 7, 8, 1, 2, 3]

    To achieve this:
    index_list.reverse() -> [8, 7, 6, 5, 4, 3, 2, 1]

    rotated_indexes = index_list[5:] + index_list[:5] -> [3, 2, 1, 8, 7, 6, 5, 4]
    index_list.reverse() -> [4, 5, 6, 7, 8, 1, 2, 3]

LEFT:   index_list -> rotation_amt = -5 (5 to left) -> [6, 7, 8, 1, 2, 3, 4, 5]

    rotated_indexes = index_list[5:] + index_list[:5] -> [6, 7, 8, 1, 2, 3, 4, 5]

"""

"""    Pseudo code duration at index from rotated index
rotated_idexes -> [4, 5, 6, 7, 8, 0, 0, 1, 1, 2, 2, 3, 3, 4]
i = value of current index in for loop:
    at first cycle -> 4 (index 0 of rotated_indexes)

1 for j in rotated_indexes if j == i (current_index_in_forloop):
    [1,1]

sum of [1,1] = 2

so duration_at_index = 2
"""

"""    duration at index from original list

for i in rotated_indexes:
    duration_at_index = list[i]

"""

"""     Pseudo code for calculating rest duration

Recombined:     [4, 5, 6, 7, 8, 0, 0, 1, 1, 2, 2, 3, 3, 4] --output--> durations = [1,1,1,1,2,2,2,2,1] & rest_duration = 1

rest_duration = 0
for index, i in enumerate(rotated_indexes):
    # calculate rest_duration
    if index == 0 and duration_at_index > 1:
        print('\nDuration at index is at least 2')

        # Ceck if duration at index[0] is split between last and first index because of the rotation
        for j in rotated_indexes[:duration_at_index]:
            print('same number?:', rotated_indexes[:duration_at_index])

            # Add 1 to rest_duration for every pulse that's at the beginning of the sequence instead of the end
            if(j != i):
                rest_duration += 1
"""
