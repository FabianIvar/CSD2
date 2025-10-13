# plays timestamps out of a dictionary once
from pygame import mixer
import time


# sum(duration_sequence)*quarter_note = cycle_time in seconds in this case 8.5
cycle_time = 8.5

# sum(duration_sequence)
cycle_duration = 17

# sorted_timestamps per layer
event_dictionary = {
    'layer_0': {
        'timestamps': [0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.5, 4.5, 5.0, 5.5, 6.0, 6.5, 7.0, 7.5, 8.0],
        'audio_file_name': 'kick.wav',
        'time_durations': [0.5, 0.5, 0.5, 0.5, 0.5, 1.0, 1.0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5],
        'channel': 0},
    'layer_1': {
        'timestamps': [0, 1.0, 2.0, 3.0, 4.5, 6.0, 7.5],
        'audio_file_name': 'snare.wav',
        'time_durations': [1.0, 1.0, 1.0, 1.5, 1.5, 1.5, 1.0],
        'channel': 1},
    'layer_2': {
        'timestamps': [0, 1.0, 2.5, 4.0, 5.5, 6.5, 7.5],
        'audio_file_name': 'hihat.wav',
        'time_durations': [1.0, 1.5, 1.5, 1.5, 1.0, 1.0, 1.0],
        'channel': 2},
    'layer_3': {
        'timestamps': [0, 4.5],
        'audio_file_name': 'perc.wav',
        'time_durations': [4.5, 4.0],
        'channel': 3}}

""" Quick syntax test from Ciska's code

=======================================
>>> testlist = []
>>> if testlist:
...     print(True)
... else:
...     print(False)
...
False
=======================================
>>> testlist.append('boom')
>>> if testlist:
...     print(True)
... else:
...     print(False)
...
True
=======================================
emtpy list makes if statement run the code after else:

"""

"""
def retrieve_timestamp(layer_name, playback_pos):

    timestamp_list = event_dictionary[layer_name]['timestamp']
    # e.g. [0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.5, 4.5, 5.0, 5.5, 6.0, 6.5, 7.0, 7.5, 8.0]

    if playback_pos < cycle_duration:
        return timestamp_list[playback_pos]
    else:
        print(layer_name,'has no timestamps left.'+'\n'+'something went wrong...')
        # return 'cycle_finished' # for looping maybe playback_position = 0?"""

# print("time zero:", time_zero,'\n')

"""while playback_position < cycle_duration:
    current_time = time.time() - time_zero

    for index, layer_name in enumerate(event_dictionary):

        inactive_channel = pygame.mixer.find_channel(force = True)
        current_sample = pygame.mixer.Sound('assets/soundFiles/'+event_dictionary[layer_name]['sound'])
        current_timestamp = event_dictionary[layer_name]['timestamp'][playback_position]


        if(current_time >= event_dictionary[layer_name]['timestamp'][playback_position]):

            play_time = int(time_durations[layer_name][playback_position]*1000)
            inactive_channel.play(current_sample, maxtime = play_time)
    playback_position += 1
    # print('playback_position',playback_position)
    print('\n\nCurrent Timestamp: '+str(current_timestamp),'\nCurrent Sample: '+event_dictionary[layer_name]['sound'],'\nPlayback Position:', playback_position,'\n')
else:
    time.sleep(max([max(time_durations[layer_name]) for layer_name in time_durations]))
    print('length of longest sample:',max([max(time_durations[layer_name]) for layer_name in time_durations]))
    exit()"""


#first only one layer

"""for layer in event_dictionary:
    time_zero = time.time()
    layer_timestamps = event_dictionary[layer]['timestamp']
    playback_position = 0

    print('Current layer is:', layer)
    print("Time zero is:", time_zero,'\n')

    if layer_timestamps:
        ts = layer_timestamps.pop(0)
    else:
        continue


    while playback_position < cycle_duration:
        now = time.time() - time_zero

        channel = pygame.mixer.find_channel(force = True)
        sample = pygame.mixer.Sound('assets/soundFiles/'+event_dictionary[layer]['sound'])

        if(now >= ts):
            print('now:',now)
            channel.play(sample)
            if layer_timestamps:
                ts = layer_timestamps.pop(0)
            else:
                break

        time.sleep(0.001)
else:
    print('No timestamps left -> exit program')
    exit()"""

mixer.init()

# creates a channel for every layer
mixer.set_num_channels(len(event_dictionary)) # Should be len(sample_settings) when implementing
print('\n\nAmount of layers:',len(event_dictionary),'\n')

def sort_by_timestamp(input_list):
    return input_list[0]

def convert_to_events(zip_dict, expected_length): #give expected_length as input

    if(False in [(expected_length == zip_dict[key_name]) for key_name in zip_dict]):
        print('\n\n================ZIP_OWN_DICT================\n\nAll note events in cycle:')

        sorted_values = []

        for index in range(expected_length):
            values = [zip_dict[layer][index] for layer in zip_dict]
            print('Values of index', str(index)+':', values)
            sorted_values.append(values)

        print('\nValues to be sorted:', '\n'+str(sorted_values))
        sorted_values.sort(key=sort_by_timestamp)

        print('\nSorted values:', '\n'+str(sorted_values))

    else:
        print('Something went wrong, not every key has the same amount of values')

    zipped_dict = dict(zip([index for index in range(len(sorted_values))],sorted_values))

    print('\nzipped_dict:','\n'+str(zipped_dict))

    return zipped_dict

def combine(*inputs):
    """Combines all inputs into one list"""

    # print('\ninput is:\n',inputs, '\nType', type(inputs), len(inputs))

    # print('\ncheck if input is a list:\n',inputs[0], '\nType', type(inputs[0]))

    if isinstance(inputs[0],int):
        # print("\ninput is an int and can't be combined:\n\noutput is:\n",inputs[0])
        return list(inputs)

    # print('\ncheck if list in:\n',[[i for i in inputs[j]] for j in range(len(inputs))][0])

    if False in [isinstance(value, list) for value in [[lists
        for lists in inputs[tuple_number]]
            for tuple_number in range(len(inputs))][0]]:

        # print('\nno lists in inputs...\ncheck if inputs are in a tuple:\n',type(inputs),'\n', inputs)
        if isinstance(inputs, tuple):
            inputs = list(inputs)[0]
            # print('\ninput was in tuple,\n remove tuple\n return:', inputs)
            return inputs
        else:
            # print('!!something went wrong!!')
            return inputs

    # print('\nfound at least one list!')

    output = []

    for j in range(len(inputs)):
        for i in inputs[j]:
            output.extend(i)
        # print('\ntemporary output is:\n',type(output),'\n', output)

    # print('\noutput is:\n',type(output),'\n', output)
    return output

def combine_layers():

    # input_dict = event_dictionary -> For readability
    input_dict = event_dictionary
    print('\ninput_dict:\n',input_dict, '\n')

    print('Layers:\n',[i
        for i in input_dict], '\n')

    key_dict = [input_dict[j]
        for j in input_dict]
    print('Key_dict:\n',key_dict, '\n')
    # print('Key_dict:\n',[key_dict[i]['timestamps'] for i in range(len(key_dict))], '\n')

    key_names = [name
        for name in key_dict[0]]
    print('Key_names:\n',key_names, '\n')

    # everytime I use list comprehension it puts everything in another list. I do [0] to fix this
    all_values = [[[input_dict[layer][name]
        for layer in input_dict]
        for name in key_names]][0]

    print('\nall_values:\n',all_values,'\n\n',all_values[0])

    key = [i for i in range(len(all_values[0]))]
    all_combined_lengths = {}
    combined_dict = {}
    combined_layer_dict = {}

    # test = []
    for index, name in enumerate(key_names):
        combined_layer_dict[name] = dict(zip(key, all_values[index]))
        combined_dict[name] = combine(list(combined_layer_dict[name].values()))
        # test += [combined_layer_dict[i] for i in combined_layer_dict][index]
        print('\ndict values:\n',[combined_layer_dict[name][i] for i in range(len(combined_layer_dict[name]))])
        print('\nlength of current dict:\n',len(combine([combined_layer_dict[name][i] for i in range(len(combined_layer_dict[name]))])))

        all_combined_lengths[name] = len(combine([combined_layer_dict[name][i]
            for i in range(len(combined_layer_dict[name]))]))

    print('\n\ncombined_layer_dict:\n',combined_layer_dict)
    print('\n--->all_combined_lengths:\n',all_combined_lengths)
    print('\n\ncombined_dict:\n',combined_dict)

    # expected number of values in a layer (every layer should be the same length)
    expected_length = max([all_combined_lengths[i]
        for i in all_combined_lengths])
    print('\n\n expected_length:\n',expected_length)

    names_below_expected = [key_name
        for key_name in all_combined_lengths
        if all_combined_lengths[key_name] != expected_length]
    print('\n\n names_below_expected:\n',names_below_expected)

    """ test:
    Assigning a new value to an existing key overwrites the values stored in this key.
    did a test:
    ========================================================================
    >>> dict1 = dict.fromkeys(['a','b','c','d'], [1,2,3,4])
    >>> dict1['a'] = 'test if this works'
    >>> dict1
    {'a': 'test if this works', 'b': [1, 2, 3, 4], 'c': [1, 2, 3, 4], 'd': [1, 2, 3, 4]}
    ========================================================================
    """

    print('------------\n',list(combined_layer_dict[name].keys()))

    #keyname to base expected layer lengths off of
    """length_keyname might not always be at the same index in a list..
    maybe fix later? very low priority"""
    length_keyname = [name
        for name in all_combined_lengths if all_combined_lengths[name] == expected_length][0]
    print('length_keyname\n',length_keyname)

    layer_lengths = [len(length)
        for length in [combined_layer_dict[length_keyname][i]
        for i in range(len(combined_layer_dict))]]

    print('layer_lengths:',layer_lengths)

    for name in names_below_expected:
        values_to_add = []
        for index, layer in enumerate(combined_dict):
            values_to_add += [combined_dict[name][index] for number in range(layer_lengths[index])]

            print('------------\n',combined_layer_dict[name][index])

        combined_dict[name] = values_to_add

    print('\ncombined_dict:\n',combined_dict)

    return [combined_dict,expected_length]
    # zipped_dictionary = convert_to_events(combined_dict, expected_length)

combined_dictionary = combine_layers()
# index 1 = expected amount of values of each key in the dict
expected_length = combined_dictionary[1]
# index 0 = the combined_dictionary
event = convert_to_events(combined_dictionary[0], expected_length)

print('\n|=------------=(NOTE_EVENTS)=------------=|\n  evnt_num | ts | sample | dur_sec | chan')
[print('|-----------------------------------------|\n',i, event[i]) for i in event]

# player :) finally

# pos stands for playback position -> decides what event to play

# old = len(ts)


# if ts:
#     timestamp = ts.pop(0)
# else:
#     print('No timestamps left -> exit program')
#     exit()

# pos stands for playback position
pos = 0
time_zero = time.time()

# enable_check = input('check? y/N')

# time.sleep(1)
# mixer.Sound('assets/soundFiles/kick.wav').play()

while pos < expected_length:

    # channel = pygame.mixer.Channel(event[pos][3])
    # sample = pygame.mixer.Sound('assets/soundFiles/'+event[pos][1])

    # For readability
    timestamp = event[pos][0]
    sample = mixer.Sound('assets/soundFiles/'+event[pos][1])
    play_time = event[pos][2]
    channel = mixer.Channel(event[pos][3])

    # print(pos)
    # print(pos,event[pos][0],event[pos][1],event[pos][3])

    # if enable_check == 'y':
    #     print(pos,timestamp,sample,channel)
    #     time.sleep(0.1)
    #     pos += 1

    now = time.time() - time_zero

    if(now >= timestamp):
        # print(sound_file,'played at',now)

        channel.play(sample)
        print('playing:',sample, '\nat timestamp:',pos)
        pos += 1

    time.sleep(0.001)


        # timestamp = ts.pop(0)
else:
    if(not channel.get_busy()):
        print('No timestamps left -> exit program')


# event_player = [start_timestamp_player]*len(event_dictionary)

"""# for index, layer in enumerate(event_dictionary):
#     print('List of Parameters for',str(layer)+':')
#     print('- Audio File Name:\n'+event_dictionary[layer]['audio_file_name'],'\n')
#     print('- Timestamps:','\n'+str(event_dictionary[layer]['timestamps']))
#     print('- Time Durations:\n'+str(time_durations[layer]))
#     print('- Channel Number:',index)
    # start_timestamp_player(event_dictionary[layer]['audio_file_name'], event_dictionary[layer]['timestamps'], time_durations['layer_0'], index)"""

""" Sources
Exit function:              https://www.geeksforgeeks.org/python/python-exit-commands-quit-exit-sys-exit-and-os-_exit/
Find available channel:     https://www.pygame.org/docs/ref/mixer.html#pygame.mixer.find_channel
Run functions in parallel:  https://stackoverflow.com/questions/7207309/how-to-run-functions-in-parallel
.fromkeys dict method:      https://www.geeksforgeeks.org/python/python-dictionary-fromkeys-method/
.extend list method:        https://www.geeksforgeeks.org/python/python-list-extend-method/
isinstance function:        https://www.w3schools.com/python/ref_func_isinstance.asp
"""
