"""
1) make var for pulse, note and bpm
2) make def for generate pattern
3) duration = int(num_pulses/num_notes)


"""

num_pulses = 16
num_notes = 5

def euclidean(num_pulses, num_notes):
    """ Generates a Euclidean Rhythm """
    duration = int(num_pulses/num_notes)            # Lengte van de noot
    remainder = num_pulses - (num_notes*duration)   # Wat er overblijft
    euclidean_rhythm = [duration] * num_notes       # Vult lijst met duration

    for i in range(remainder):
        euclidean_rhythm[i] += 1                    # Distribute remaining pulsees amongst durations stored in the generated_rhythm array
    return euclidean_rhythm

print('euclidean rhythm is: ',euclidean(num_pulses,num_notes))
