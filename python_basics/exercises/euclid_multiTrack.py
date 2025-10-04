#largely the same as euclid_duration, but with an option for multiple tracks implemented

from list_transform import rotate
from list_transform import constrain

"""

1) include tracks amount in arguments of euclidean function
2) create nested array filled with durations
3) create nested for loop that distributes remainder amongst stored values in each array

"""

num_pulses = 16
num_notes = 5
num_tracks = 3
rotation = 6


def euclidean(num_pulses, num_notes, track_amt):
    """ Generates a Euclidean Rhythm """
    duration = int(num_pulses/num_notes)                            # Lengte van de noot
    remainder = num_pulses - (num_notes*duration)                   # Wat er overblijft
    euclidean_rhythm = [[duration] * num_notes] * num_tracks        # Vult lijst met duration

    for j in range(num_tracks):
        for i in range(remainder):
            euclidean_rhythm[j][i] += 1                    # Distribute remaining pulses amongst durations stored in the generated_rhythm array
    return euclidean_rhythm




euclidean_rhythm = euclidean(num_pulses,num_notes,num_tracks)
print('euclidean rhythm is: ',euclidean_rhythm)
print('rotated list is: ', rotate(euclidean_rhythm, 2))
