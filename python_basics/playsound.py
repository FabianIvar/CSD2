from pygame import mixer
import time


mixer.init()
mixer.music.load("playsoundFiles/snare.mp3")
mixer.music.set_volume(0.7)
amt = int(input("Number of repetitions: "))
spd = float(input("Time in seconds between repetitions:"))



for i in range(amt):
  print(i+1)
  mixer.music.play()
  time.sleep(spd)
else:
    print("Finished!")
