# timestamp_dict_player combined with all other code

from pygame import mixer
import time
from list_transform import rotate
import random
import inp_v3 as inp
import numpy as np
from inp_v3 import validateType as check
from inp_v3 import toggle_print

#settings function with user input certain values need to be constrained
# TODO: player uses volume of samples
# TODO: validate input for 'name of sample' -> let user pick sample from list -> list is composed of files present in  the directory /assets/soundFiles
# TODO: Full input validation working
# TODO: player actually loops
# TODO: implement partial randomize -> user decides bounds of random function -> input is less boring
# TODO: export as MIDI
# TODO: prepare for presentation in class -> collect deliverables
# TODO: implement decreasing deviation
# TODO: implement sample variation and better sound design
# maybe a dictionary with possible options and an enumerate over the dictionary so the user can just type a number to pick a sample

def settings(**set):

    """Returns global_settings and sample_settings stored in a dictionary

    Parameter set['file_name']: The name of the sample to configure and return settings of
    Parameter set['type']: The type of setting to configure and return
            Options: "global", "sample"""


    match set['type']:

        case 'global':
            global_config = {
                "num_layers": max(check(input("Number of layers: "),'int'), 1),
                "num_pulses": max(check(input("Number of pulses: "),'int'),1),
                "bpm": inp.constrain(check(input("Beats per minute: "),'int'), 10, 10000),
                "state": 'configured'}
            return global_config

        case 'sample':
            if global_settings['state'] != 'configured':
                print("global settings are not yet configured")
            else:
                sample_config = {
                    "sample": set['file_name'] + '.wav',
                    "num_pulses": global_settings['num_pulses'],
                    "num_notes": check(input("Number of notes: "),'int'),
                    "volume": inp.constrain(check(input("Gain (value between 0-1): "),'float'), 0, 1),
                    "rotation_amt": check(input("amt to rotate: "),'int')}
                sample_config.update({'num_notes': inp.constrain(sample_config['num_notes'], 0, global_settings['num_pulses'])})
                return sample_config

"""def settings(**set): # temp

    #Returns global_settings and sample_settings stored in a dictionary

    #Parameter set['file_name']: The name of the sample to configure and return settings of
    #Parameter set['type']: The type of setting to configure and return
            # Options: "global", "sample"


    match set['type']:

        case 'global':
            global_config = {
                "num_layers": inp.constrain(check(4,'int'), 0, 4),
                "num_pulses": check(random.randint(10,20),'int'),  # cant be zero because division by zero
                "bpm": inp.constrain(check(120,'int'), 1, 1000),
                "state": 'configured'}
            return global_config

        case 'sample':
            if global_settings['state'] != 'configured':
                print("global settings are not yet configured")
            else:
                sample_config = {
                    "sample": set['file_name'] + '.wav',
                    "num_pulses": global_settings['num_pulses'],
                    "num_notes": check(random.randint(1,16),'int'), #can't be 0 because division by zero
                    "volume": inp.constrain(check(1,'float'), 0, 1),
                    "rotation_amt": check(random.randint(1,10),'int')}
                sample_config.update({'num_notes': inp.constrain(sample_config['num_notes'], 0, global_settings['num_pulses'])})
                return sample_config"""

# Colors in terminal! source: https://stackoverflow.com/questions/3940128/how-do-i-reverse-a-list-or-loop-over-it-backwards#3940144
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

def pack_sample_settings():
    """Starts sample settings configuration and saves the settings of each sample in nested dictionaries"""
    num_layers = global_settings['num_layers']
    configuration = {}

    for i in range(global_settings['num_layers']):
        sample_name = input('Pick sample for layer ' + str(i+1) + ': ')
        # + str(i) to prevent sample settings not being saved because of duplicates, can also be done with ennumerate but I didn't know this at the time
        configuration[f'layer_{i}'] = settings(type = "sample", file_name = sample_name)

    print(configuration)
    return configuration

global_settings = settings(type = 'global')
sample_settings = pack_sample_settings()

def generate_euclidean_durations():
    """
    Creates a nested dictionary containing durations generated by a euclidean algorithm for every layer
    """

    enable_comments = 1

    euclidean_sequence = {}

    for layer_name in sample_settings:

        # Improves readability
        num_notes = sample_settings[layer_name]['num_notes']
        num_pulses = global_settings['num_pulses']
        rotation_amount = sample_settings[layer_name]['rotation_amt']

        duration = int(num_pulses / num_notes)
        remainder = num_pulses - (num_notes * duration)
        duration_sequence = [duration] * num_notes

        # Distributes remainder amongst values stored in duration_sequence
        for j in range(remainder):
            duration_sequence[j] += 1

        toggle_print('duration_sequence',duration_sequence,enable_comments)

        rotated_sequence = inp.rotate(duration_sequence, rotation_amount)

        toggle_print((rotated_sequence),enable_comments)

        euclidean_sequence[layer_name] = rotated_sequence


    return euclidean_sequence

def get_values_between(**arg): # arg is a dictionary containing the arguments used in this function
    """
    Returns a list of a given length with even steps between two given values

    parameter arg['start']: The starting value of the sequence
    parameter arg['stop']: The end value of the sequence
    parameter arg['num']: The amount of values
    """

    """ Uitleg & Voorbeeld default_values:

    Het is een soort forloop die waardes uit een dictionary leest en op basis van
    de gelezen waardes een bepaald stukje code wel of niet uitvoerd.

        Wat er soortvan staat:
    Als de naam van een parameter die geconfigureerd wordt in 'default_values' NIET
    voorkomt in de dictionary aan parameters die is meegegeven aan de functie.
    Zet dan deze parameter die mist naar de 'default_value'.

    ==================================================================================

    Voorbeeld:

    > Meegegeven parameters zijn: arg['stop'] en arg['num']:
    > default_values zijn: start:0 en num:10

    > for default_setting_name in default_values:
        // de eerste 'default_setting_name' is 'start'
        // de eerste 'input_argument_name' is ook 'start'

        1e loop (loopt dus twee keer want er zijn twee input arguments gegeven (len(arg) = 2)
        > if(not {True for input_argument_name in input_arguments if default_setting_name in input_argument_name}):
            // if start in start -> True
            // if(not True) -> niet de code uitvoeren :)

        2e loop (tweede 'default_setting_name' is 'num',    tweede 'input_argument_name' is 'stop')
            // if num in stop -> False
            // if(not True) -> wel de code uitvoeren >:]

            > arg[default_setting_name] = default_values[default_setting_name]
                // default_setting_name = 'num'
                // dus arg['num'] = default_values['num']
                // default_value van 'num' = 10 dus arg['num'] = 10

    ==================================================================================
    """

    enable_comments = True

    input_arguments = arg.keys()
    default_values = {'start':-10, 'num':10}

    # Sets devault value if 'start' or 'num' argument aren't present in the arg dictionary
    for default_setting_name in default_values:
        if(not {True for input_argument_name in input_arguments if default_setting_name in input_argument_name}):
            arg[default_setting_name] = default_values[default_setting_name]

    list_range = np.linspace(arg['start'], arg['stop'], num=arg['num'], endpoint=True)
    toggle_print(f'start/stop values: {arg['start']}, {arg['stop']} \nlist_range: {list_range}',enable_comments)
    return list_range

def generate_deviations(amount): # arg is a dictionary containing the arguments used in this function

    """
    Returns a nested dictionary for every layer containing the values that will deviate the timestamps
    """

    """ Pseudo code
    After this I need to figure out how to wrap a timestamp like -8.461538461571429 to something playable.
    Maybe something like:

    dev_timestamp = timestamp + deviation
    cycle_time = num_pulses * quarter_notelength
    cycle_amount = 10

    if dev_timestamp < 0:
        wrapped_dev_timestamp = abs(totalLength - dev_timestamp)

    if dev_timestamp > cycle_time:
        wrapped_dev_timestamp =

    ==================================================================

    K = kick
        original timestamp = 1
        deviated_by = -10

    S = snare
        original timestamp = 4
        deviated_by = 10

    if deviation > 0
        <every cylce deviation decreases by 1>

    if deviation < 0:
        <every cycle deviation increases by 1>


    kick:
    7 0 1 2 3 4 5 6 7 0 1

    snare:
    6 5 4 3 2 1 0 7 6 5 4

        0   1   2   3   4   5   6   7
    1) [_] [_] [_] [_] [_] [_] [S] [K]
    2) [K] [_] [_] [_] [_] [S] [_] [_]
    3) [_] [K] [_] [_] [S] [_] [_] [_]
    4) [_] [_] [K] [S] [_] [_] [_] [_]
    5) [_] [_] [S] [K] [_] [_] [_] [_]
    6) [_] [S] [_] [_] [K] [_] [_] [_]
    7) [S] [_] [_] [_] [_] [K] [_] [_]
    8) [_] [_] [_] [_] [_] [_] [K] [S]
    9) [_] [_] [_] [_] [_] [_] [S] [K]
    10)[K] [_] [_] [_] [_] [S] [_] [_]
    11)[_] [K] [_] [_] [S] [_] [_] [_]


    """

    deviation = {}

    for layer_name in euclidean_durations:
        duration_list = euclidean_durations[layer_name][0]
        print('\n\nlayer_name: '+layer_name+'\n'+str(euclidean_durations[layer_name]))

        half_duration = sum(duration_list)/2

        range_half_duration = get_values_between(start = -half_duration, stop = (half_duration), num = len(duration_list))
        print(range_half_duration)
        rounded_range = [round(float(value),4) for value in range_half_duration]
        scaled_rounded_range = [value / half_duration for value in rounded_range]

        shuffledFactor = random.sample(scaled_rounded_range, len(scaled_rounded_range)) # random.sample makes a copy, random.shuffle modifies list
        deviation[layer_name] = [amount*shuffledFactor.pop() for value in scaled_rounded_range]

    print('\n\nDeviations:')
    [print(i, deviation[i]) for i in deviation]
    print('\n')
    return deviation

# Collect generated deviations into a dictionary
euclidean_durations = generate_euclidean_durations()
print('euclidean_durations:',euclidean_durations)
deviations = generate_deviations(10)

def duration_to_timestamp():
    """
    Convert durations to timestamps
    """

    timestamp_dictionary = {}

    for layer_name in sample_settings:
        timestamps = []
        durations_current_layer = euclidean_durations[layer_name][0]
        rest_duration = euclidean_durations[layer_name][1] # Delay before first timestamp starts
        quarter_note = 60/global_settings['bpm']
        time_duration = [durations_current_layer[i]*quarter_note for i in range(len(durations_current_layer))]

        print('Timedurations '+str(layer_name)+':',time_duration)

        for j in range(len(durations_current_layer)):
            timestamps.append(sum([time_duration[k] for k in range(j)]))

        timestamp_dictionary[layer_name] = [i+rest_duration for i in timestamps]
        sample_settings[layer_name]['time_durations'] = time_duration #kinda a weird way to add time durations to the sample settings dictionary

    print('\n\nTimestamp Dictionary:', timestamp_dictionary,'\n')
    return timestamp_dictionary

timestamps = duration_to_timestamp()

def pack_layers():
    """Collect durations, deviations, volumes, etc. of all layers into one dictionary
    so these values can be used by the player"""
    packed_layers = {}

    # TODO: Maybe make a global setting for max deviation?

    for index, i in enumerate(sample_settings):
        packed_layers[i] = {
            'timestamp': timestamps[i],
            'audio_file_name': sample_settings[i]['sample'],
            'time_durations': sample_settings[i]['time_durations'],
            'channel': index,
            'duration': euclidean_durations[i],
            'deviation': deviations[i],
            'volume': sample_settings[i]['volume']}
        print('\n'+i + '\n\n' + str(packed_layers[i]))

    return packed_layers

# generate a list with durations with 'generate_sequence' for every track and combine them into a dictionary
packed_layers = pack_layers()

# Prints the values in generate_sequences
print()
[print(i, packed_layers[i]) for i in packed_layers]

mixer.init()

# creates a channel for every layer
mixer.set_num_channels(32) # Should be len(sample_settings) when implementing
print('\n\nAmount of layers:',len(packed_layers),'\n')

def convert_to_events(zip_dict, expected_length): #give expected_length as input

    enable_comments = False

    if(False in [(expected_length == zip_dict[key_name]) for key_name in zip_dict]):
        toggle_print(f'{color.REDB}\n|=------------------------=({color.RESET}ZIP_OWN_DICT{color.REDB})=------------------------=|',
            f'{color.WHITE}\n\nAll note events in cycle:',enable_comments)
        sorted_values = []

        for index in range(expected_length):
            values = [zip_dict[layer][index] for layer in zip_dict]
            toggle_print(f'{color.GRAY}Values of index', str(index)+':', values,enable_comments)
            sorted_values.append(values)

        toggle_print(f'{color.WHITE}\nValues to be sorted:', color.GRAY, '\n'+str(sorted_values),enable_comments)
        sorted_values.sort(key=inp.sort_by_timestamp)
        toggle_print(f'{color.WHITE}\nSorted values:', color.GRAY,'\n'+str(sorted_values),enable_comments)
    else:
        toggle_print('Something went wrong, not every key has the same amount of values',enable_comments)

    zipped_dict = dict(zip([index for index in range(len(sorted_values))],sorted_values))

    toggle_print(f'{color.WHITE}\nzipped_dict:',color.GRAY,'\n'+str(zipped_dict),enable_comments)

    print(color.RESET,end='')
    return zipped_dict

def transform_layers():
    """Prepares layers for being converted into events"""

    enable_comments = False

    # everytime I use list comprehension with nested listsit puts everything in another list. I do [0] sometimes to fix this
    input_dict = packed_layers
    key_dict = [input_dict[j]
        for j in input_dict]
    key_names = [name
        for name in key_dict[0]]
    all_values = [[[input_dict[layer][name]
        for layer in input_dict]
        for name in key_names]][0]

    toggle_print('\ninput_dict:\n',input_dict, '\n',enable_comments)
    toggle_print('Key_dict:\n',key_dict, '\n',enable_comments)
    toggle_print('Key_names:\n',key_names, '\n',enable_comments)
    toggle_print('\nall_values:\n',all_values,'\n\n',all_values[0],enable_comments)
    toggle_print('Layers:\n',[i for i in input_dict], '\n',enable_comments)

    key = [i for i in range(len(all_values[0]))]
    all_combined_lengths = {}
    combined_dict = {}
    combined_layer_dict = {}

    for index, name in enumerate(key_names):
        combined_layer_dict[name] = dict(zip(key, all_values[index]))
        combined_dict[name] = inp.combine(list(combined_layer_dict[name].values()))

        toggle_print('\ndict values:\n',[combined_layer_dict[name][i] for i in range(len(combined_layer_dict[name]))],enable_comments)
        toggle_print('\nlength of current dict:\n',len(inp.combine([combined_layer_dict[name][i] for i in range(len(combined_layer_dict[name]))])),enable_comments)

        all_combined_lengths[name] = len(inp.combine([combined_layer_dict[name][i]
            for i in range(len(combined_layer_dict[name]))]))

    toggle_print('\n\ncombined_layer_dict:\n',combined_layer_dict,enable_comments)
    toggle_print('\n--->all_combined_lengths:\n',all_combined_lengths,enable_comments)
    toggle_print('\n\ncombined_dict:\n',combined_dict,enable_comments)

    # expected number of values in a layer (every layer should be the same length)
    # Length_keyname is keyname to base expected layer lengths off of
    expected_length = max([all_combined_lengths[i]
        for i in all_combined_lengths])
    names_below_expected = [key_name
        for key_name in all_combined_lengths
        if all_combined_lengths[key_name] != expected_length]
    length_keyname = [name
        for name in all_combined_lengths if all_combined_lengths[name] == expected_length][0]
    layer_lengths = [len(length)
        for length in [combined_layer_dict[length_keyname][i]
        for i in range(len(combined_layer_dict[length_keyname]))]]

    # Extends the values of keys in 'combined_dict' untill they reach the expected amount
    # uses the layer_lengths of key that has the most values -> length_keyname
    for name in names_below_expected:
        values_to_add = []
        for index, layer in enumerate(layer_lengths):
            values_to_add += [combined_dict[name][index] for number in range(layer_lengths[index])]
        combined_dict[name] = values_to_add

    toggle_print('\n\n expected_length:\n',expected_length,enable_comments)
    toggle_print('\n\n names_below_expected:\n',names_below_expected,enable_comments)
    toggle_print('length_keyname\n',length_keyname,enable_comments)
    toggle_print('---->layer_lengths:',layer_lengths,enable_comments)
    toggle_print('\ncombined_dict with added values:\n',combined_dict,enable_comments)

    return [combined_dict,expected_length]

combined_dictionary = transform_layers()
# index 1 = expected amount of values of each key in the dict
expected_length = combined_dictionary[1]
# index 0 = the combined_dictionary
event = convert_to_events(combined_dictionary[0], expected_length)

print(f'{color.REDB}\n|=------------------------=({color.RESET}NOTE_EVENTS{color.REDB})=------------------------=|\n')
print(f'{color.WHITE} evnt_num {color.GRAY}| {color.WHITE}timestamp {color.GRAY}|',
    f'{color.WHITE}sample {color.GRAY}| {color.WHITE} chan {color.GRAY}|',
    f'{color.WHITE}dur_sec {color.GRAY}| {color.WHITE}dur {color.GRAY}|',
    f'{color.WHITE}dev {color.GRAY}| {color.WHITE}vol ')
[print(f'{color.GRAY}-------------------------------------------------------------------\n',
    color.WHITE, i, color.GRAY, event[i]) for i in event]
print(f'{color.RESET}')

# pos = playback_position
pos = 0
time_zero = time.time()

while pos < expected_length:

    # For readability
    timestamp = event[pos][0]
    sample = mixer.Sound('assets/soundFiles/'+event[pos][1])
    play_time = event[pos][2]
    # Uses assigned channel unless that channel is busy, then it will pick an available channel
    channel = mixer.Channel(event[pos][3])

    if channel.get_busy():
        channel = mixer.find_channel()

    now = time.time() - time_zero

    if(now >= timestamp):
        # print(sound_file,'played at',now)
        try:
            channel.play(sample)
        except:
            mixer.Channel(event[pos][3])
        else:
            channel.play(sample)
        print(timestamp,'|',event[pos][1],event[pos][2],event[pos][3])
        pos += 1

    time.sleep(0.001)

print()
while channel.get_busy():
    time.sleep(0.001)
else:
    print(f'{color.YELLOWB}No timestamps left -> exit player{color.RESET}')

""" Sources
Exit function:              https://www.geeksforgeeks.org/python/python-exit-commands-quit-exit-sys-exit-and-os-_exit/
Find available channel:     https://www.pygame.org/docs/ref/mixer.html#pygame.mixer.find_channel
Run functions in parallel:  https://stackoverflow.com/questions/7207309/how-to-run-functions-in-parallel
.fromkeys dict method:      https://www.geeksforgeeks.org/python/python-dictionary-fromkeys-method/
.extend list method:        https://www.geeksforgeeks.org/python/python-list-extend-method/
isinstance function:        https://www.w3schools.com/python/ref_func_isinstance.asp
values between range:       https://stackoverflow.com/questions/64338441/how-to-get-the-values-between-a-range-in-python#64338552
multiply list:              https://www.geeksforgeeks.org/python/sum-function-python/
devide list:                https://www.geeksforgeeks.org/python/divide-all-elements-of-a-list-by-a-number-in-python/
list comprehension:         https://www.geeksforgeeks.org/python/python-list-comprehension/
check dict for item:        https://www.geeksforgeeks.org/python/check-if-dictionary-value-contains-certain-string-with-python/
dict comprehension:         https://www.geeksforgeeks.org/python/python-dictionary-comprehension
numer odd or even?:         https://stackoverflow.com/questions/21837208/check-if-a-number-is-odd-or-even-in-python#21837247
shuffle list:               https://www.geeksforgeeks.org/python/python-ways-to-shuffle-a-list/
random:                     https://www.w3schools.com/python/ref_module_random.asp
random.sample:              https://www.w3schools.com/python/ref_random_sample.asp
colored text in terminal:   https://stackoverflow.com/questions/287871/how-do-i-print-colored-text-to-the-terminal#287944
"""
