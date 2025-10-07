# mostly the same as euclid_multiTrack.py but with user input stored in a dictionary

from list_transform import rotate
from list_transform import constrain
import inp

def settings(**set):
    """global_settings and sample_settings stored in a dictionary"""
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
    """Starts sample settings configuration and saves the settings of each sample in nested dictionaries"""
    num_layers = global_settings['num_layers']
    configuration = {}

    for i in range(num_layers):
        sample_name = input('Pick sample for layer ' + str(i+1) + ': ')
        # + str(i) to prevent sample settings not being saved because of duplicates, can also be done with ennumerate but I didn't know this at the time
        configuration[sample_name + '_' + str(i)] = settings(type = "sample", file_name = sample_name)

    return configuration

# names are kinda confusing, global_settings & sample_settings are the settings saved in an list.
# global_config & sample_config is the variable in the scope of the settings function.
global_settings = settings(type = 'global')
sample_settings = pack_sample_settings()

print(sample_settings.keys())

""" Question?
euclidean_sequence = [[duration] * num_notes] * num_layers
Dit werkt niet for some reason???
als je dan een index probeert aan te passen verandert die alle indexes.
Dus in dit geval moet je wel gewoon een for-loop gebruiken om duration te initialiseren.
!! Stel deze vraag misschien in de les !!
"""

def generate_sequence():
    """Generates a Euclidean Rhythm"""

    euclidean_sequence = {}

    for i in range(global_settings['num_layers']):
        this_sample = list(sample_settings.keys())[i]   # Sample relevant in the current cycle of the for-loop
        sound = sample_settings[this_sample]            # For readability, 'sound' is a dictionary that contains the settings of the sample relevant in the current cycle of the for-loop
        print('current sample:',this_sample)

        duration = int(global_settings['num_pulses'] / sound['num_notes'])          # pulses/notes
        remainder = global_settings['num_pulses'] - (sound['num_notes'] * duration) # Wat er overblijft -> pulses - (notes*duration)
        duration_sequence = [duration] * sound['num_notes']
        print('pre-remainder distribution:',duration_sequence)

        # Distribute remainder amongst values in duration_sequence
        for j in range(remainder):
            duration_sequence[j] += 1
        print('post-remainder distribution:',duration_sequence)

        # Rotate duration_sequence
        rotated_sequence = inp.rotate(duration_sequence, sound['rotation_amt'])

        euclidean_sequence[this_sample] = {'duration': rotated_sequence, 'volume': sound['volume']}

    return euclidean_sequence

euclidean_sequence = generate_sequence()
print(euclidean_sequence)

print('\n')
for i in range(len(list(euclidean_sequence.keys()))): # unreadable mess, prints
    print(list(euclidean_sequence.keys())[i],euclidean_sequence[list(euclidean_sequence.keys())[i]])
