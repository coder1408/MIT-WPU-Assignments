from gpiozero import LED
from gpiozero import Button
from gpiozero import TrafficLights
import time

# TrafficLights(red, amber, green)
lights = TrafficLights(25, 8, 7)
button = Button(21)


def traffic(hour):
  t = time.localtime()
  h = t.tm_hour
  lights.amber.on()
  time.sleep(2)
  lights.amber.off()
  if (21 > h and 6 < h):
    lights.green.on()
    time.sleep(5)
    lights.green.off()
  else:
    lights.red.on()
    time.sleep(5)
    lights.red.off()

def wakey(hour, min):
  cnt = 0
  while cnt < 10:
    if (hour == 6 and min == 40):
      lights.green.on()
      lights.red.on()
      lights.amber.on()
      time.sleep(1)
      lights.green.off()
      lights.red.off()
      lights.amber.off()
      time.sleep(1)
    cnt+=1

while True:
  w = time.localtime()
  wakey(w.tm_hour, w.tm_min)
  button.when_pressed = traffic

