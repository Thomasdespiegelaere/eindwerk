import difflib
import firebase_admin
from firebase_admin import credentials
from firebase_admin import db
import json
import dictdiffer
import serial # importeer de serial liberary
import time # importeer de time library

ser = serial.Serial('/dev/ttyACM0', 9600)#timeout=5) # defineer de seriele poort

cred = credentials.Certificate(r'/home/pi/Documents/eindwerk-ba782-firebase-adminsdk-9ohgt-fdc72788ca.json')
default_app = firebase_admin.initialize_app(cred, {
    'databaseURL': 'https://eindwerk-ba782-default-rtdb.europe-west1.firebasedatabase.app/' # stel de database url in
	})
while True:
    #ref = db.reference("/Dagen/Maandag") # initialiseer de database root voor ref
    #maandag = ref.update({"Fornuis":True})   #update de waarde van de database
    database = db.reference("/Dagen").get() # haal de waarden af van database root dagen
    reset = db.reference("/reset").get()

    standaard = {                          # standaard week waarden
        "Dinsdag" : {
          "Boiler" : True,
          "Fornuis" : True,
          "Lichten" : False,
          "Vaatwas" : True
        },
        "Donderdag" : {
          "Boiler" : True,
          "Fornuis" : True,
          "Lichten" : True,
          "Vaatwas" : False
        },
        "Maandag" : {
          "Boiler" : False,
          "Fornuis" : True,
          "Lichten" : True,
          "Vaatwas" : True
        },
        "Vrijdag" : {
          "Boiler" : True,
          "Fornuis" : True,
          "Lichten" : True,
          "Vaatwas" : True
        },
        "Woensdag" : {
          "Boiler" : True,
          "Fornuis" : True,
          "Lichten" : True,
          "Vaatwas" : True
        },
        "Zaterdag" : {
          "Boiler" : True,
          "Fornuis" : True,
          "Lichten" : True,
          "Vaatwas" : True
        },
        "Zondag" : {
          "Boiler" : True,
          "Fornuis" : True,
          "Lichten" : True,
          "Vaatwas" : True
        }
      }

    waarde = ser.readline().decode('utf-8').strip() # lees de data en decodeer hem
    if (waarde == "dagen"):
        if (reset == False):
            for diff in list(
                dictdiffer.diff(database, standaard)):  # check de verschillen tussen de database en de standaard week
                verschil = diff[1]  # zoek waar het verschil zit bv: maandag.Fornuis
                getal = diff[2]  # als er een verschil is haal dan de waarden op
                verandering = getal[0]# haal de verandering in de database af
                while ser.readline().decode('utf-8').strip() != '>':
                    continue
                ser.write(verschil.encode('utf-8')) #stuur verschil door naar de arduino                    
                while ser.readline().decode('utf-8').strip() != '>': # ga pas verder als arduino een > stuurt
                    continue
                aanpasingen = str(verandering)
                ser.write(aanpasingen.encode('utf-8')) #stuur verandering door naar de arduino                            
                #print(verschil)  # print waar het verschil zit
                #print(verandering)  # print de verandering van de database  
            break
        elif (reset == True):
            ser.write('normale weekplanning'.encode('utf-8'))
    else:
        print("geen aanpasingen")



