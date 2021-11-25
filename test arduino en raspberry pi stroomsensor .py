#!/usr/bin/python3

import serial # importeer de serial liberary
import time # importeer de time library

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=5) # defineer de seriele poort



# read from Arduino
while True:
    waarde = ser.readline().decode('utf-8').strip() # lees de data
    if (waarde == ""): # als er niets wordt doorgegeven print dan niks
        print("")
    else:
        print(waarde) # als er wel een waarde binnenkomt print dan de waarde
