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
    'layer_0': {'timestamps':[0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.5, 4.5, 5.0, 5.5, 6.0, 6.5, 7.0, 7.5, 8.0],
        'audio_file_name': 'kick.wav',
        'time_durations' : [0.5, 0.5, 0.5, 0.5, 0.5, 1.0, 1.0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5]},
    'layer_1': {
        'timestamps':[0, 1.0, 2.0, 3.0, 4.5, 6.0, 7.5],
        'audio_file_name': 'snare.wav',
        'time_durations' : [1.0, 1.0, 1.0, 1.5, 1.5, 1.5, 1.0]},
    'layer_2': {
        'timestamps':[0, 1.0, 2.5, 4.0, 5.5, 6.5, 7.5],
        'audio_file_name': 'hihat.wav',
        'time_durations' : [1.0, 1.5, 1.5, 1.5, 1.0, 1.0, 1.0]},
    'layer_3': {
        'timestamps':[0, 4.5],
        'audio_file_name': 'perc.wav',
        'time_durations' : [4.5, 4.0]}}

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
print('\n\nAmount of layers:',len(event_dictionary))


example_list = [[1,2],[2,'bruh'],[6,'yoo'],[3,'should be third'],[4,11253.123126],[5,'should be fifth']]



ts = []
for i in event_dictionary:
    ts += event_dictionary[i]['timestamps']

def sort_timestamp(input_list):
    print('input_list')
    return input_list[0]

def zip_own_values(input_dictionary):
    zipped_dictionary = []
    keys = []
    unsorted_values = []
    # expected number of values in a layer
    num_layer_values = sum([len(input_dictionary[key]) for key in input_dictionary])/4

    if(False in [num_layer_values == for num_layer_values in ]) == )
        for index in range(num_layer_values):

            values = [input_dictionary[layer][index] for layer in input_dictionary]
            print('Values of index', str(index)+':', values)
            unsorted_values.append(values)


    # print('\n\nlisted_keys:',len(keys),'\n')
    # print('\n\nZIPPED DICTIONARY:',zipped_dictionary)

    # zipped_dictionary = {k:v for (k,v) in zip(keys, values)}

    return zipped_dictionary

def combine_layers_and_sort():

    channel = 0

    all_timestamps = []
    all_time_durations =[]
    samples = []
    channels = []
    # keyname_list = []

    for index, layer_name in enumerate(event_dictionary):
        all_timestamps += event_dictionary[layer_name]['timestamps']
        all_time_durations += event_dictionary[layer_name]['time_durations']
        samples += [event_dictionary[layer_name]['audio_file_name'] for i in event_dictionary[layer_name]['timestamps']]
        channels += [index for i in event_dictionary[layer_name]['timestamps']]

    keyname_list = [i for i in event_dictionary[layer_name]]
    keyname_list.append('channels')
    combined_dictionary = dict(zip(keyname_list,[all_timestamps, samples, all_time_durations, channels]))
    zip_dictionary = zip_own_values(combined_dictionary)

    print('\n\Combined_dictionary:\n',combined_dictionary,'\n\n')
    print('this',keyname_list)
    print('this',len(all_timestamps))
    print('this',len(all_time_durations))
    print('this',len(samples))
    print('this',len(channels))


    # sorted_event = dict(sort_event_list)

    # sorted_event = {
    #     'values': { all_timestamps,
    #         'time_duration': all_time_durations,
    #         'sample': samples,
    #         'channel': channels,
    #         'old': len(ts)}}


    # sorted_event.sort(key=sort_timestamp)

    return zip_dictionary

# event_dictionary['old'] = len(ts)

# timestamps = [values[0] for values in sorted_event]
# channel = pygame.mixer.Channel(index)



old = len(ts)

event = combine_layers_and_sort()
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

    time.sleep(0.001)

# event_player = [start_timestamp_player]*len(event_dictionary)

# for index, layer in enumerate(event_dictionary):
#     print('List of Parameters for',str(layer)+':')
#     print('- Audio File Name:\n'+event_dictionary[layer]['audio_file_name'],'\n')
#     print('- Timestamps:','\n'+str(event_dictionary[layer]['timestamps']))
#     print('- Time Durations:\n'+str(time_durations[layer]))
#     print('- Channel Number:',index)
    # start_timestamp_player(event_dictionary[layer]['audio_file_name'], event_dictionary[layer]['timestamps'], time_durations['layer_0'], index)



""" Sources
Exit function:              https://www.geeksforgeeks.org/python/python-exit-commands-quit-exit-sys-exit-and-os-_exit/
Find available channel:     https://www.pygame.org/docs/ref/mixer.html#pygame.mixer.find_channel
Run functions in parallel:  https://stackoverflow.com/questions/7207309/how-to-run-functions-in-parallel
"""
