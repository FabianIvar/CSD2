from list_transform import rotate


"""
1) make var for pulse, note and bpm
2) make def for generate pattern
3) duration = int(num_pulses/num_notes)
4) make list that is as long as the amount of notes then fill list with duration
5) distribute remaining pulses amongst values stored in list


"""

num_pulses = 16
num_notes = 5
rotation = 6

def euclidean(num_pulses, num_notes):
    """ Generates a Euclidean Rhythm """
    duration = int(num_pulses/num_notes)            # Lengte van de noot
    remainder = num_pulses - (num_notes*duration)   # Wat er overblijft
    euclidean_rhythm = [duration] * num_notes       # Vult lijst met duration

    for i in range(remainder):
        euclidean_rhythm[i] += 1                    # Distribute remaining pulsees amongst durations stored in the generated_rhythm array
    return euclidean_rhythm


euclidean_rhythm = euclidean(num_pulses,num_notes)
print('euclidean rhythm is: ',euclidean_rhythm)
print('rotated list is: ', rotate(euclidean_rhythm, 2))
