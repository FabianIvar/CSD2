from pygame import mixer
from os import walk
# from name import beat_generator_presets
import time

mixer.init()

#load soundfiles
kick = mixer.Sound("playsoundFiles/kick.wav")
snare = mixer.Sound("playsoundFiles/snare.wav")
hihat = mixer.Sound("playsoundFiles/hihat.wav")
perc = mixer.Sound("playsoundFiles/perc.wav")


filenames = next(walk("beat_generator_presets"), (None, None, []))[2]
configuration = []

#contrain between two values
const = lambda a,b,c: b if a<b else (c if a>c else a)
#greatest common denominator
gcd = lambda a,b: a if b == 0 else gcd(b,a%b)
freq = lambda a:60/a

def preset(x):
    # print('\n')
    if x == 'y':
        for i in range(len(filenames)-1):
            if i == 0:
                print('\n','|', end=' ')
            print(filenames[i], end=' | ')
        print('\n')
        return preset_picker(input('Enter full filename including extention (e.g. <presetname>.txt): '))
    elif x == 'n':
        print("\n"+"-={Configure settings manually}=-", end='\n\n')
    else:
        preset(inp_check(x,'other'))

def preset_picker(name):
    try:
        with open('beat_generator_presets/'+name, "r") as f:
            picked_preset = f.read().splitlines()
            return picked_preset
        print('Set configuration to',configuration)
    except:
        return preset_picker(inp_check(name, 'other'))

#check if string matches expected type, if not re-enter string. Prevents ValueError
def inp_check(inp,type):
        match type:
            case 'int':
                try:
                    int(inp)
                except ValueError:
                    return inp_check(input("Must be an integer, try again: "), 'int')
                except TypeError:
                    return inp_check(inp,'other')
                else:
                    return int(inp)
            case 'float':
                try:
                    float(inp)
                except ValueError:
                    return inp_check(input("Must be a float, try again: "), 'float')
                except TypeError:
                    return inp_check(inp,'other')
                else:
                    return float(inp)
            case 'other' | _:
                try:
                    int(inp[0])
                except ValueError:
                    try:
                        float(inp[0])
                    except ValueError:
                        return input("doesn't understand " + inp + ", try again: ")
                    else:
                        return float(inp[0])
                else:
                    return int(inp[0])

def configure():
    track_amt = inp_check(input("Number of tracks (1-4):"),'int')
    p_amt = inp_check(input("Number of pulses:"),'int')
    n_amt = const(inp_check(input("Number of notes:"),'int'), 0, p_amt)
    bpm = const(inp_check(input("Beats per minute:"),'int'), 0, 512)
    vol = const(inp_check(input("Gain (value between 0-1):"),'float'), 0, 1)
    rot_amt = inp_check(input('amt to rotate:'),'int')
    return [track_amt,p_amt,n_amt,bpm,vol,rot_amt]

use_preset = input("Open preset (y-n):") #maybe need to do use_preset[0]
configuration = preset(use_preset)

if use_preset == 'n':
    configuration = configure()
    print('\nCurrent configuration is',configuration,'save it as a new preset?',' \n - If yes, enter new preset name (e.g. <newpreset>.txt)',' \n - If no, enter n')
    new_preset = input('\n')
    if new_preset !='n':
        new_file = open('beat_generator_presets/'+new_preset, "w")
        for q in range(len(configuration)):
            new_file.write(str(configuration[q])+"\n")
        new_file.close()
        with open('beat_generator_presets/'+new_preset, "r") as f:
            print(f.read())
            # picked_preset = f.read().splitlines()
            # return picked_preset
    # configuration =

"""
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

snare.set_volume(vol)

for i in range(p_amt):
  print(i+1)
  snare.play()
  time.sleep(freq(bpm)*(1/p_amt))
else:
    print("Finished!")
    time.sleep(snare.get_length())
"""


#rotate
def rotate(list,amt):
    for i in range(const(abs(amt),0,abs(amt))):
        if amt <0:
            n=list[0].pop(0) #have to add another forloop later so that multitrack works (replace [0] with [i])
            list.append(n)
        elif amt >0:
            n=list.pop(-1)
            list.insert(0, n)
        else:
            print("something went wrong")
        # print(list)
    return list

generated_rhythm = [1,2,3,4,5,6,7]

rotated_list = rotate(generated_rhythm, inp_check(configuration[5], 'int'))
print(rotated_list)

#assign deviation to notes using devatoinfactor

#Sources:
"""
gcd:                        1 https://stackoverflow.com/questions/11175131/code-for-greatest-common-divisor-in-python#11175154
list filesnames:            2 https://stackoverflow.com/questions/3207219/how-do-i-list-all-files-of-a-directory#3207973
tell python to do nothing:  3 https://stackoverflow.com/questions/19632728/how-do-i-get-a-python-program-to-do-nothing#19632742
reading from .txt file      4 https://www.geeksforgeeks.org/python/with-statement-in-python/#
try/except function         5 https://www.w3schools.com/python/python_try_except.asp
indentifying variable type  6 https://www.w3schools.com/python/python_ref_string.asp
"""
