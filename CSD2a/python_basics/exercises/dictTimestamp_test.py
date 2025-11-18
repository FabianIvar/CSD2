# Test to convert durations to timestamps with an option to implement deviation

from pygame import mixer
import time
from inp_v2 import validateType as check
from inp_v2 import constrain

mixer.init()
kick_0 = mixer.Sound("assets/soundFiles/kick.wav")
snare_1 = mixer.Sound("assets/soundFiles/snare.wav")
hihat_2 = mixer.Sound("assets/soundFiles/hihat.wav")

# Settings example
packed_layers = {'kick_0': {
    'duration': [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    'timestamp': 'not implemented yet',
    'deviation': [-2.307692307714286, -0.7692307692857143, -8.461538461571429, 6.923076923142856, 10.0, 5.384615384571428, 8.461538461571429, -5.384615384571428, 2.307692307714286, 0.7692307692857143, 3.8461538461428573, -6.923076923142856, -10.0, -3.8461538461428573],
    'volume': 1},
    'snare_1': {'duration': [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    'timestamp': 'not implemented yet',
    'deviation': [1.1111111112, 7.7777777778, 5.5555555556, -5.5555555556, -3.3333333334000006, 10.0, -7.7777777778, 3.3333333334000006, -1.1111111112, -10.0],
    'volume': 1},
    'hihat_2': {'duration': [8, 8],
    'timestamp': 'not implemented yet',
    'deviation': [10.0, -10.0],
    'volume': 1},
    'perc_3': {'duration': [8, 8],
    'timestamp': 'not implemented yet',
    'deviation': [-10.0, 10.0],
    'volume': 1}}

def duration_to_timestamp(input_list):
    """
    Convert durations to timestamps

    Parameter input_list: list with durations to convert to timestamps
    """

    timestamps = []

    for i in range(len(input_list)):
        timestamps.append(sum([input_list[j] for j in range(i)]))

    return timestamps

for i in packed_layers:

    packed_layers[i]['timestamp'] = duration_to_timestamp(packed_layers[i]['duration'])
    print('\n'+i+':', '\n'+str(packed_layers[i].keys())+':', '\n'+str(packed_layers[i].values()), '\n')
