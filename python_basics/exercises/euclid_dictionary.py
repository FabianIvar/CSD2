#largely the same as euclid_multiTrack.py but with user input stored in a dictionary

from list_transform import rotate
from list_transform import constrain
import inp

"""

1) include tracks amount in arguments of euclidean function
2) create nested array filled with durations
3) create nested for loop that distributes remainder amongst stored values in each array

"""

def settings(**set):
    match set['type']:

        case 'global':
            global_config = {
                "num_layers": inp.constrain(inp.check(input("Number of layers (1-4): "),'int'), 0, 4),
                "num_pulses": inp.check(input("Number of pulses: "),'int'),
                "bpm": inp.constrain(inp.check(input("Beats per minute: "),'int'), 0, 512),
                "state": 'configured'}
            return global_config

        case 'sample':
            if global_settings['state'] != 'configured':
                print("global settings are not yet configured")
            else:
                sample_config = {
                    "sample": set['file_name'] + '.wav',
                    "num_pulses": global_settings['num_pulses'],
                    "num_notes": inp.check(input("Number of notes: "),'int'),
                    "volume": inp.constrain(inp.check(input("Gain (value between 0-1): "),'float'), 0, 1),
                    "rotation_amt": inp.check(input("amt to rotate:"),'int')}
                sample_config.update({'num_notes': constrain(sample_config['num_notes'], 0, global_settings['num_pulses'])})
                return sample_config

def pack_sample_settings():
    """Starts sample setting configuration and saves the settings in nested dictionary's"""
    num_layers = global_settings['num_layers']
    configuration = {}

    for i in range(num_layers):
        sample_name = input('Pick sample for layer ' + str(i+1) + ': ')
        configuration[sample_name] = settings(type = "sample", file_name = sample_name)

    return configuration

# names are kinda confusing, global_settings are the saved in an array. global_config is the variable in the scope of the settings function

global_settings = settings(type = 'global')
sample_settings = pack_sample_settings()

print(sample_settings.keys())

""" question:
euclidean_sequence = [[duration] * num_notes] * num_layers
Dit werkt niet for some reason???
als je dan een index probeert aan te passen verandert die alle indexes.
Dus in dit geval moet je wel gewoon een for-loop gebruiken om duration te initialiseren.
!! Stel deze vraag misschien in de les !!
"""

""" duration to timestamp -> not finished yet
def duration_to_timestamp(duration,sample): # should be done after deviated_duration is calculated with deviation_factor
    timestamps = []
    playLength = 60/global_settings['bpm'] # length in seconds of one beat
    full_cycle_length = playLength*global_settings['num_pulses']

    for i in range(sample['num_notes']):
        timestamps.append(duration*playLength)

    return timestamps"""

def euclidean(num_layers, num_pulses, num_notes):
    """Generates a Euclidean Rhythm"""

    euclidean_sequence = {} # .update lijkt handig voor als je dingen achteraf nog wilt veranderen terwijl het al aan het afspelen is ofzo? kan geen kwaad in ieder geval

    for i in range(global_settings['num_layers']):
        this_sample = list(sample_settings.keys())[i] # sample that's relevant in the current cycle of the for-loop
        print(this_sample)

        duration = int(global_settings['num_pulses'] / sample_settings[this_sample]['num_notes'])       # pulses/notes
        remainder = global_settings['num_pulses'] - (num_notes*duration)                                # Wat er overblijft -> pulses - (notes*duration)
        # timestamps = duration_to_timestamp(duration, sample_settings[this_sample])
        timestamps = 'timestamp'

        # euclidean_sequence.update({"sample": input('Pick sample for layer ' + str(i+1) + ': ')})
        euclidean_sequence[list(sample_settings.keys())[i]] = {'timestamp': timestamps, 'volume': sample_settings[this_sample]['volume']}
        for j in range(num_notes):
            pass

    print(euclidean_sequence)

    # print(euclidean_sequence)

    print('remainder', remainder)

    for i in range(num_layers):         # Distribute remaining pulsees amongst durations stored in the generated_sequence array
        for j in range(remainder):
            euclidean_sequence[j][i] = euclidean_sequence[j][i] + 1
            print(euclidean_sequence[j])
            print(j)

    return euclidean_sequence


# num_pulses,num_notes,num_layers

# euclidean_sequence = euclidean(setting['num_layers'],setting['num_pulses'],setting['num_notes'])
# print(set.keys(), '\n', set.values())
# print('euclidean rhythm is: ',euclidean_sequence)
# print('rotated list is: ', rotate(euclidean_sequence[0], setting['rotation_amt']))
