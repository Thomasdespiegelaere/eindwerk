#!/usr/bin/python3

import serial
import time



ser = serial.Serial('/dev/ttyACM0', 9600, timeout=5)



# read from Arduino

waarde = ser.read()
print ("Read input " + waarde.decode("utf-8") + " from Arduino")



while 1:

        # write something back
        ingang = input("---> ")
        if ingang == 'on' :
            ser.write(b'1')
            aan = ser.read()
            print ("Read input " + aan.decode("utf-8") + " from Arduino")
        elif ingang == 'off' :
            ser.write(b'0')
            uit = ser.read()
            print ("Read input " + uit.decode("utf-8") + " from Arduino")
        time.sleep(1)