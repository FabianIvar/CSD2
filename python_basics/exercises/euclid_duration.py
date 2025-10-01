"""
1) make var for pulse, note and bpm
2) make def for generate pattern
3) duration = int(pulses/notes)


"""

pulses = 16
notes = 5

def euclidean(pulses, notes): #maakt een ritme in het geval dat de noten perfect passen binnen de hoeveelheid pulsen, verdeeld daarna de overgebleven pulsen over de opgeslagen waarden
    duration = int(pulses/notes)
    remainder = pulses - (notes*duration) #wat er overblijft
    euclidean_rhythm = []
    for i in range(notes):
		if i % step_size  == 0: #i % step_size is nul wanneer i een veelvoud is van 3, dus bij 3, 6, 9, 12 etc. zo wordt True alleen gepushed op de plekken waar die een sample moet afspelen
			generated_rhythm[i].push(True)
			instert_point.push(i)
		else:
			generated_rhythm[i].push(False)
	for r in rest:
		generated_rhythm[instert_point[j]].push(False) #distribuute remaining pulses amongst durations stored in the generated_rhythm array
	return generated_rhythm

euclidean(pulses,notes):
