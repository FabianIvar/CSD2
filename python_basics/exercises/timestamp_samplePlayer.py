from pygame import mixer
import time
from inp_check import check
from inp_check import const

mixer.init()
snr = mixer.Sound("playsoundFiles/snare.wav")
kck = mixer.Sound("playsoundFiles/kick.wav")
kit = [snr,kck]

#settings
amt = check(input('Enter the amount of repetitions: '), 'int')
trck = const(check(input('Enter the amount of tracks (1-2): '), 'int'),1,2)
spd = check(input('Enter time between sample triggers in seconds: '), 'float_int')
vol = const(check(input("Gain (value between 0-1): "), 'float'), 0,1)
seq = []

snr.set_volume(vol)
# print(amt,spd,vol)

#sample player
for i in range(trck):
    for j in range(amt):
        seq.append([])
        if trck >1:
            seq[len(seq)-1] = [i,spd*j]
        else:
            seq[len(seq)-1] = spd*j
        # print(seq)
print(seq)
t = time.time()
counter = 0
event = seq[0]

while True:
    now = time.time() - t
    if(now >= event[1]):
        if counter < amt*trck:
            kit[event[0]].play()
            counter += 1
            event = seq[counter]
            print(event)
        else:
            break
    time.sleep(0.001)

time.sleep(snr.get_length())
print(seq)




        # seq[0][j].append(i+1)
        # seq[0][j].append(spd*j)



# #sample player
# for i in range (trck-1):
#     for j in range(amt):
#         seq.append([])
#     for k in range(amt):
#         seq[].append([])
