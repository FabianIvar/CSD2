from pygame import mixer
from os import walk
import inp      # inp stands for 'input', it is a python file where I store various functions
# from name import
import time

mixer.init()

#load soundfiles
kick = mixer.Sound("assets/soundFiles/kick.wav")
snare = mixer.Sound("assets/soundFiles/snare.wav")
hihat = mixer.Sound("assets/soundFiles/hihat.wav")
perc = mixer.Sound("assets/soundFiles/perc.wav")

filenames = next(walk("assets/presets"), (None, None, []))[2]
settings = []

#greatest common denominator
gcd = lambda a,b: a if b == 0 else gcd(b,a%b)
freq = lambda a:60/a

def preset(use_preset):
    if use_preset == 'y':
        for i in range(len(filenames)-1):
            if i == 0:
                print('\n','|', end=' ')
            print(filenames[i], end=' | ')
        print('\n')
        return preset_picker(input('Enter full filename including extention (e.g. <presetname>.txt): '))
    elif use_preset == 'n':
        print("\n"+"-={Configure settings manually}=-", end='\n\n')
        settings = configure_settings()
        print('\nCurrent configuration is',settings,'save it as a new preset?',' \n - If yes, enter new preset name (e.g. <newpreset>.txt)',' \n - If no, enter n')
        new_preset = input('\n')
        if new_preset !='n':
            new_file = open('assets/presets/'+new_preset, "w")
            for q in range(len(settings)):
                new_file.write(str(settings[q])+"\n")
            new_file.close()
            with open('assets/presets/'+new_preset, "r") as f:
                print(f.read())
        return settings
    else:
        preset(inp.check(use_preset,'other'))

def preset_picker(name):
    try:
        with open('assets/presets/'+name, "r") as f:
            picked_preset = f.read().splitlines()
            return picked_preset
            print('Set configuration to',picked_preset)
    except:
        return preset_picker(inp.check(name, 'other'))

def configure_settings():
    track_amt = inp.check(input("Number of tracks (1-4):"),'int')
    p_amt = inp.check(input("Number of pulses:"),'int')
    n_amt = inp.constrain(inp.check(input("Number of notes:"),'int'), 0, p_amt)
    bpm = inp.constrain(inp.check(input("Beats per minute:"),'int'), 0, 512)
    vol = inp.constrain(inp.check(input("Gain (value between 0-1):"),'float'), 0, 1)
    rot_amt = inp.check(input('amt to rotate:'),'int')
    return [track_amt,p_amt,n_amt,bpm,vol,rot_amt]

''' preset selector steps:

1) ask user if they would like to use a preset; 'y' if yes 'n' if no
2) variable called settings = output of a function called 'preset()' with user input ('y' or 'n') as argument
3) if argument == 'y' then execute a function called 'preset_picker()'
    if argument == 'n' then print('configure manually') and execute a fuction called 'configure()'
4) preset_picker returns settings saved in the preset as an array, configure asks user for input and sets values for multiple variables



'''

# use_preset = input("Open preset (y-n):")
settings = preset(input("Open preset (y-n): "))
print('these are the settings:', settings)

""" 🌀 -=:Generate pattern:=- 🌀 (not finished)
def euclidean(p, n): #maakt een ritme in het geval dat de noten perfect passen binnen de hoeveelheid pulsen, verdeeld daarna de overgebleven pulsen over de opgeslagen waarden
    step_size = int(p/n)
    rest = p - (n*step_size) #wat er overblijft
	insert_point = [] #plek waar de pulsen die overblijven worden ge-insert zodat de remaining pulses eerlijk verdeeld zijn over de rusten tussen alle noten. Een zonder noot = False
    for i in n*step_size:
		if i % step_size  == 0: #i % step_size is nul wanneer i een veelvoud is van 3, dus bij 3, 6, 9, 12 etc. zo wordt True alleen gepushed op de plekken waar die een sample moet afspelen
			generated_rhythm[i].push(True)
			instert_point.push(i)
		else:
			generated_rhythm[i].push(False)
	for r in rest:
		generated_rhythm[instert_point[j]].push(False) #distribuute remaining pulses amongst durations stored in the generated_rhythm array
	return generated_rhythm

seq = [] * n_amt

for i in range(track_amt-1):
    seq[i].append(seq[0])
"""
snare.set_volume(float(settings[4]))

for i in range(p_amt):
  print(i+1)
  snare.play()
  time.sleep(freq(bpm)*(1/p_amt))
else:
    print("Finished!")
    time.sleep(snare.get_length())


#rotate
""" rotate        elif amt >0:
            n=list.pop(-1)
            list.insert(0, n)
        else:
            print("something went wrong")
        # print(list)
    return list
"""

generated_rhythm = [1,2,3,4,5,6,7]

rotated_list = inp.rotate(generated_rhythm, inp.check(settings[5], 'int'))
print(rotated_list)

#assign deviation to notes using deviation_factor



#Sources:
"""
gcd:                        1   https://stackoverflow.com/questions/11175131/code-for-greatest-common-divisor-in-python#11175154
list filesnames:            2   https://stackoverflow.com/questions/3207219/how-do-i-list-all-files-of-a-directory#3207973
tell python to do nothing:  3   https://stackoverflow.com/questions/19632728/how-do-i-get-a-python-program-to-do-nothing#19632742
reading from .txt file      4   https://www.geeksforgeeks.org/python/with-statement-in-python/#
try/except function         5   https://www.w3schools.com/python/python_try_except.asp
indentifying variable type  6   https://www.w3schools.com/python/python_ref_string.asp
markdown formatting         7   https://www.markdownguide.org/basic-syntax/
array methods               8   https://www.w3schools.com/python/python_ref_list.asp
functions in python         9   https://www.w3schools.com/python/python_functions.asp
for loop in python_basics   10  https://www.w3schools.com/python/python_for_loops.asp
constrain function:         11  https://stackoverflow.com/questions/34837677/a-pythonic-way-to-write-a-constrain-function#34837691
dictionary's in python      12  https://www.w3schools.com/python/python_dictionaries_access.asp
"""
