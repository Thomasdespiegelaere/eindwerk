#!/usr/bin/python3

import serial
import time



ser = serial.Serial('/dev/ttyACM0', 9600, timeout=5) # defineer de seriele poort





waarde = ser.read() # lees de waarde van de arduino 
print ("Read input " + waarde.decode("utf-8") + " from Arduino") # decodeer de waarde



while 1:


        ingang = input("---> ")    # schrijf een antwoord terug schrijven
        if ingang == 'on' :        #als je on schrijft dan stuurt hij een 1 naar de arduino
            ser.write(b'1')
            aan = ser.read()       #lees het antwoord en decodeerd het weer
            print ("Read input " + aan.decode("utf-8") + " from Arduino")
        elif ingang == 'off' :       #als je off schrijft dan stuurt hij een 0 naar de arduino
            ser.write(b'0')
            uit = ser.read()        #lees het antwoord en decodeerd het weer
            print ("Read input " + uit.decode("utf-8") + " from Arduino")
        time.sleep(1)    #wacht 1 seconde