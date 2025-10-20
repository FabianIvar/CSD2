from midiutil import MIDIFile

# constrains values higher than the max MIDI pitch number to 127
# creating a file with the same name overwrites the previous file
degrees  = [60, 62, 64, 65, 67, 69, 71, 72] # MIDI note number
track    = 0   # don't know what this does, just leave at 0
channel  = 0   # don't have to change this :) i think
time     = 1   # delay in beats before note
duration = 1   # In beats
tempo    = 135  # In BPM
volume   = 100 # 0-127, as per the MIDI standard

MyMIDI = MIDIFile(1) # One track, defaults to format 1 (tempo track
                     # automatically created)
MyMIDI.addTempo(track,time, tempo)

for index, pitch in enumerate(degrees):
    MyMIDI.addNote(track, channel, pitch, [0,1.5,2,3.3,0.6,5,6,7][index], duration, volume)
    time = time + 1

with open("assets/midiFiles/major-scale.mid", "wb") as output_file:
    MyMIDI.writeFile(output_file)
