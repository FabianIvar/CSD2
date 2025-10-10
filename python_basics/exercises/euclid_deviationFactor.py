# mostly the same as euclid_dictionary.py but with user deviation implemented

from list_transform import rotate
import random
import inp_v2 as inp
import numpy as np
from inp_v2 import validateType as check

""" settings function with user input certain values need to be constrained
def settings(**set):

    # Returns global_settings and sample_settings stored in a dictionary
    #
    # Parameter set['file_name']: The name of the sample to configure and return settings of
    # Parameter set['type']: The type of setting to configure and return
            # Options: "global", "sample"



        case 'global':
            global_config = {
                "num_layers": inp.constrain(check(input("Number of layers (1-4): "),'int'), 0, 4),
                "num_pulses": check(input("Number of pulses: "),'int'),
                "bpm": inp.constrain(check(input("Beats per minute: "),'int'), 0, 512),
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
                    "rotation_amt": check(input("amt to rotate:"),'int')}
                sample_config.update({'num_notes': constrain(sample_config['num_notes'], 0, global_settings['num_pulses'])})
                return sample_config"""

def settings(**set):
    """
    Returns global_settings and sample_settings stored in a dictionary

    Parameter set['file_name']: The name of the sample to configure and return settings of
    Parameter set['type']: The type of setting to configure and return
            Options: "global", "sample"

    """
    match set['type']:

        case 'global':
            global_config = {
                "num_layers": inp.constrain(check(4,'int'), 0, 4),
                "num_pulses": check(16,'int'),  # cant be zero because division by zero
                "bpm": inp.constrain(check(120,'int'), 0, 512),
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
                return sample_config

def pack_sample_settings():
    """Starts sample settings configuration and saves the settings of each sample in nested dictionaries"""
    num_layers = global_settings['num_layers']
    configuration = {}

    for i in range(global_settings['num_layers']):
        """->"""# sample_name = input('Pick sample for layer ' + str(i+1) + ': ')
        # + str(i) to prevent sample settings not being saved because of duplicates, can also be done with ennumerate but I didn't know this at the time

        """->"""#configuration[sample_name + '_' + str(i)] = settings(type = "sample", file_name = sample_name)
        configuration['sample_name' + '_' + str(i)] = settings(type = "sample", file_name = 'sample_name')
    print(configuration)
    return configuration

# names are kinda confusing, global_settings & sample_settings are the settings saved in an list.
# global_config & sample_config is the variable in the scope of the settings function.
global_settings = settings(type = 'global')
sample_settings = pack_sample_settings()

# print(sample_settings.keys())

def generate_sequences():
    """Generates a Euclidean Rhythm"""

    euclidean_sequence = {}

    for i in range(global_settings['num_layers']):

        sample_keyName = list(sample_settings.keys())[i]
        sample_value = sample_settings[sample_keyName]

        duration = int(global_settings['num_pulses'] / sample_value['num_notes'])
        remainder = global_settings['num_pulses'] - (sample_value['num_notes'] * duration)

        # Fill a list with a length of <num_notes> with duration
        duration_sequence = [duration] * sample_value['num_notes']

        # Distribute remainder amongst values in duration_sequence
        with_remainder = [duration_sequence[j]+1 for j in range(remainder)]
        # for j in range(remainder):
        #     duration_sequence[j] + 1

        # Rotate duration_sequence
        rotated_sequence = inp.rotate(with_remainder, sample_value['rotation_amt'])

        # Stores the
        euclidean_sequence[sample_keyName] = rotated_sequence
        # euclidean_sequence = rotated_sequence

    return euclidean_sequence

"""def pack_sequence():
    #packs euclidean sequences for all layers into one dictionary
    packed_duration = {}

    for i in sample_settings:
        print(i + ': ' + str(generate_sequence(i)))
        packed_duration[i] = {'duration': generate_sequence(i)}

    return packed_duration

generate a list with durations with 'generate_sequence' for every t and combine them into a dictionary
packed_sequence = pack_sequence()"""

# arg is a dictionary containing the arguments used in this function
def listRange(**arg):
    """
    Returns a list of a given length with even steps between two given values

    parameter arg['start']: The starting value of the sequence
    parameter arg['stop']: The end value of the sequence
    parameter arg['num']: The amount of values
    """

    # Sets devault value if 'start' or 'num' argument aren't present in the arg dictionary
    default = {'start':0, 'num':10}
    for i in default:
        if(not {True for key in arg.keys() if i in key}): # very hard to understand but very cool! dictionary comprehension!
            arg[i] = default[i]

    listRange = np.linspace(arg['start'], arg['stop'], num=arg['num'], endpoint=True)

    return listRange

# arg is a dictionary containing the arguments used in this function
def generate_deviations(**arg):

    """
    Returns a list of a given length containing the deviation values to add to... maybe duration? *subject to change

    parameter arg['list']: list with duration values to dertermine the amount of notes and the total length
    parameter arg['amt']: maximum deviation
    *parameter arg['min']: minimum deviation not implemented yet
    """

    # For readability, 'list' represents the list thats given as an argument to the function
    list = arg['list']

    # Also for readability, 'amt' represents the maximum deviation
    amt = arg['amt']

    halfDuration = sum(list)/2

    # list <len(list)> values between -halfDuration and halfDuration in even steps
    savedRange = listRange(start = -halfDuration, stop = (halfDuration), num = len(list))

    # Convert the numpy array 'sanvedRange' to a list with rounded float values
    roundedRange = [round(float(value),4) for value in savedRange] # List comprehension!!!

    # Scale roundedRange to (min = -1 max = 1)
    scaledFactor = [value / halfDuration for value in roundedRange]

    # Shuffle scaledFactor
    shuffledFactor = random.sample(scaledFactor, len(scaledFactor)) # random.sample makes a copy, random.shuffle modifies list

    deviation = [amt*shuffledFactor.pop() for value in scaledFactor]

    return deviation

# Collect generated euclidean sequences into a dictionary
euclidean_durations = generate_sequences()

# Collect generated deviations into a dictionary
# deviations = generate_deviations()

def pack_layers():
    """Collect durations, deviations and volumes of all layers into one dictionary"""
    packed_layers = {}

    # Maybe make a global setting for max deviation?
    for i in sample_settings:
        packed_layers[i] = {
            'duration': euclidean_durations[i],
            'timestamp': 'not implemented yet',
            'deviation': generate_deviations(list = euclidean_durations[i], amt = 10),
            'volume': sample_settings[i]['volume']}
        print('\n'+i + '\n\n' + str(packed_layers[i]))

    return packed_layers

# generate a list with durations with 'generate_sequence' for every track and combine them into a dictionary
packed_layers = pack_layers()

# Prints the values in generate_sequences
print()
[print(i, euclidean_durations[i]) for i in euclidean_durations]

'''Sources
values between range:   https://stackoverflow.com/questions/64338441/how-to-get-the-values-between-a-range-in-python#64338552
multiply list:          https://www.geeksforgeeks.org/python/sum-function-python/
devide list:            https://www.geeksforgeeks.org/python/divide-all-elements-of-a-list-by-a-number-in-python/
list comprehension:     https://www.geeksforgeeks.org/python/python-list-comprehension/
check dict for item:    https://www.geeksforgeeks.org/python/check-if-dictionary-value-contains-certain-string-with-python/
dict comprehension:     https://www.geeksforgeeks.org/python/python-dictionary-comprehension
numer odd or even?:     https://stackoverflow.com/questions/21837208/check-if-a-number-is-odd-or-even-in-python#21837247
shuffle list:           https://www.geeksforgeeks.org/python/python-ways-to-shuffle-a-list/
random:                 https://www.w3schools.com/python/ref_module_random.asp
random.sample:          https://www.w3schools.com/python/ref_random_sample.asp
'''

# /Volumes/T7/Documenten/Git/CSD2/python_basics/exercises/euclid_deviationFactor.py
