# plays timestamps out of a dictionary once
import pygame
import time
from multiprocessing import Process

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

pygame.init()

# creates a channel for every layer
pygame.mixer.set_num_channels(len(event_dictionary)) # Should be len(sample_settings) when implementing
print('\n\nAmount of layers:',len(event_dictionary),'\n')

ts = []
for i in event_dictionary:
    ts += event_dictionary[i]['timestamps']




def sort_by_timestamp(input_list):
    return input_list[0]




def zip_own_values(input_dictionary):

    # expected number of values in a layer (every layer should be the same length)
    expected_length = int(sum([len(input_dictionary[key]) for key in input_dictionary])/4)

    if(False in [(expected_length == input_dictionary[key_name]) for key_name in input_dictionary]):
        print('All note events in cycle:')

        zipped_dictionary = []
        sort_values = []


        for index in range(expected_length):
            values = [input_dictionary[layer][index] for layer in input_dictionary]
            print('Values of index', str(index)+':', values)
            sort_values.append(values)

        print('\nValues to be sorted:', '\n'+str(sort_values))
        sort_values.sort(key=sort_by_timestamp)

        print('\nSorted values:', '\n'+str(sort_values))

    else:
        print('Something went wrong, not every key has the same amount of values')



    # print('\n\nlisted_keys:',len(keys),'\n')
    # print('\n\nZIPPED DICTIONARY:',zipped_dictionary)

    # zipped_dictionary = {k:v for (k,v) in zip(keys, values)}

    return zipped_dictionary



def combine(*inputs):
    """Combines all inputs into one list"""

    print('\ninput is:',inputs)

    output = [i for i in inputs][0]

    print('\ntest output for lists:', [(i,isinstance(i,list)) for i in output],'\n')

    if True in [isinstance(i,list) for i in output]:
        print('!!there are still lists left in output!!')
        return combine(output[0])
    else:
        print('output is:',output,'\n')
        return output


def combine_layers_and_sort(input_dict):

    """# channel = 0

    # all_timestamps = []
    # all_time_durations =[]
    # samples = []
    # channels = []

    # There must be a wayy better way to do this -> fix later
    for index, layer_name in enumerate(event_dictionary):
        # all_timestamps += event_dictionary[layer_name]['timestamps']
        # all_time_durations += event_dictionary[layer_name]['time_durations']
        pass"""

    # input_dict = event_dictionary -> For readability
    expected_length = len(combine([combine(input_dict[i]['timestamps']) for i in input_dict]))
    print('Expected_length:\n',expected_length, '\n')

    layers = [i for i in input_dict]
    print('Layers:\n',layers, '\n')

    key_dict = [input_dict[j] for j in layers]
    print('Key_dict:\n',[key_dict[i]['timestamps'] for i in range(len(key_dict))], '\n')


    key_names = [k for k in key_dict[0]]
    print('Key_names:\n',key_names, '\n')

    value_dict = [[key_dict[index][key_names[l]]
        for l in range(len(key_names))]
        for index in range(len(key_dict))]
    print('Value_dict:\n',value_dict, '\n')



                        #   [0,1,2,3]
    not_combined = dict(zip([i for i in range(len(key_names))], value_dict))

    not_combined[index]['samples'] = [[key_dict[index]['audio_file_name']
        for length in [not_combined[nr]['timestamps'] for nr in range(len(layers))]

        for index in range(len(layers))



]
        for i in range(len(key_dict[index]['timestamps']))]

    print('Values_not_combined:')
    [print(str(i)+':', not_combined[i]) for i in not_combined]
    print()


    # values
    # samples += [event_dictionary[layer_name]['audio_file_name'] for i in event_dictionary[layer_name]['timestamps']]
    # channels += [index for i in event_dictionary[layer_name]['timestamps']]

    for i, name in enumerate(key_names):
        combined_values = combine([values_seperate[index][i] for index in range(len(layers))])



    # print('Values:\n',[[key_dict[index][key_names[l]] for l in range(len(key_names))][index] for index in range(len(key_dict))], '\n')


    # [combine([key_dict[index][key_names[l]] for l in range(len(key_names))]) for index in range(len(key_dict))]

    """# values = [combine([input_dict[k] for k in input_dict][0][l]) for l in layers]

    # for l in layers:
        # values =
        # values = dict.fromkeys(keys, event_dict[l])[l for l in event_dict[]]

    # print('\n\n',keys,'\n')
    # values = [event_dict[layers[index]][k] for k in (keys)]
    # timestamps

    # [print(event_dict[i]) for index, i in enumerate(event_dict.values())]
    # all_timestamps = combine()
    # list_
    # print('\n\ntest',[event_dict[i for i in event_dict][j] for j in event_dict[k for k in event_dict]])"""

    all_time_durations =[]
    samples = []
    channels = []


    """
    # for-loop above defines variable 'layer_name'.
    # Last value of layer_name was 'layer_3' in this case.
    # But the specific layer won't matter because they all should be the same length
    # keyname_list = [i for i in event_dict[layers]]
    # print('\n\ntest',[i for i in event_dictionary],'\n')
    # print('hehhh????',x,keyname_list)
    # keyname_list.append('channels')
    # combined_dictionary = dict(zip(keyname_list,[all_timestamps, samples, all_time_durations, channels]))
    # combined_dictionary = dict.fromkeys(keyname_list,[all_timestamps, samples, all_time_durations, channels])
    # dict(zip(keyname_list,[all_timestamps, samples, all_time_durations, channels]))"""


    print('\nCombined_dictionary:\n',combined_dictionary,'\n\n')

    # zipped_dictionary = zip_own_values(combined_dictionary)

    # print('this',keyname_list)
    # print('this',len(all_timestamps))
    # print('this',len(all_time_durations))
    # print('this',len(samples))
    # print('this',len(channels))

    return zipped_dictionary

    # sorted_event = dict(sort_event_list)

    # sorted_event = {
    #     'values': { all_timestamps,
    #         'time_duration': all_time_durations,
    #         'sample': samples,
    #         'channel': channels,
    #         'old': len(ts)}}


    # sorted_event.sort(key=sort_timestamp)


# event_dictionary['old'] = len(ts)

# timestamps = [values[0] for values in sorted_event]
# channel = pygame.mixer.Channel(index)


event = combine_layers_and_sort(event_dictionary)

"""old = len(ts)

time_zero = time.time()

if ts:
    timestamp = ts.pop(0)
else:
    print('No timestamps left -> exit program')
    exit()

while True:

    now = time.time() - time_zero
    sample = pygame.mixer.Sound('assets/soundFiles/'+event[old-len(ts)]['sample'])
    channel = pygame.mixer.Channel(event[old-len(ts)]['channel'])

    if(now >= timestamp):
        # print(sound_file,'played at',now)
        if ts:
            event[old-len(ts)]['channel'].play(sample)
            print('playback:',old-len(ts))
            timestamp = ts.pop(0)
        else:
            if(not channel.get_Busy):
                print('No timestamps left -> exit program')
                break

    time.sleep(0.001)"""

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
