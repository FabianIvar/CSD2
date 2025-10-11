# plays timestamps out of a dictionary once
import pygame
import time

# sum(duration_sequence)*quarter_note = cycle_time in seconds in this case 8.5
cycle_time = 8.5

# sum(duration_sequence)
cycle_duration = 17

# sorted_timestamps per layer
event_dictionary = {
    'layer_0': {'timestamp':[0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.5, 4.5, 5.0, 5.5, 6.0, 6.5, 7.0, 7.5, 8.0], 'sound': 'kick.wav'},
    'layer_1': {'timestamp':[0, 1.0, 2.0, 3.0, 4.5, 6.0, 7.5], 'sound': 'snare.wav'},
    'layer_2': {'timestamp':[0, 1.0, 2.5, 4.0, 5.5, 6.5, 7.5], 'sound': 'hihat.wav'},
    'layer_3': {'timestamp':[0, 4.5], 'sound': 'perc.wav'}}

# should be replaced in final code by durations
time_durations = {
    'layer_0': [0.5, 0.5, 0.5, 0.5, 0.5, 1.0, 1.0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5],
    'layer_1': [1.0, 1.0, 1.0, 1.5, 1.5, 1.5, 1.0],
    'layer_2': [1.0, 1.5, 1.5, 1.5, 1.0, 1.0, 1.0],
    'layer_3': [4.5, 4.0]
}

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

pygame.init()

# creates a channel for every layer
pygame.mixer.set_num_channels(len(event_dictionary)) # Should be len(sample_settings) when implementing
print('\n\nAmount of layers:',len(event_dictionary))

time_zero = time.time()
print("time zero:", time_zero,'\n')


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

for layer in event_dictionary:
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
    exit()

def start_timestamp_player(sound_file, timestamps):
    layer_timestamps = timestamps

    if layer_timestamps:
        ts = layer_timestamps.pop(0)
    else:
        print('timestamps_finished_playing')

# channel =
# sound = pygame.mixer.Channel.get_sound











""" Sources
Exit function:              https://www.geeksforgeeks.org/python/python-exit-commands-quit-exit-sys-exit-and-os-_exit/
Find available channel:     https://www.pygame.org/docs/ref/mixer.html#pygame.mixer.find_channel
"""
