from pygame import mixer
import time

mixer.init()
snare = mixer.Sound("playsoundFiles/snare.wav")

#https://stackoverflow.com/questions/5996881/how-to-limit-a-number-to-be-within-a-specified-range-python#5996949
def const(n, min, max):
    if n < min:
        property
        return min
    elif n > max:
        property
        return max
    else:
        return n

amt = int(input("Number of repetitions: "))
spd = float(input("Time in seconds between repetitions:"))
vol = const(float(input("Gain (value between 0-1):")), 0, 1)

snare.set_volume(vol)

for i in range(amt):
  print(i+1)
  snare.play()
  time.sleep(spd)
else:
    print("Finished!")
    time.sleep(snare.get_length())
