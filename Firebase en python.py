import difflib
import firebase_admin
from firebase_admin import credentials
from firebase_admin import db
import json
import dictdiffer

cred = credentials.Certificate(r'C:\Users\tdesp\OneDrive\Documenten\6EL\gip\eindwerk-ba782-firebase-adminsdk-9ohgt-fdc72788ca.json')
default_app = firebase_admin.initialize_app(cred, {
    'databaseURL': 'https://eindwerk-ba782-default-rtdb.europe-west1.firebasedatabase.app/' # stel de database url in
	})

#ref = db.reference("/Dagen/Maandag") # initialiseer de database root voor ref
database = db.reference("/Dagen").get() # haal de waarden af van database root dagen
#maandag = ref.update({"Fornuis":True})   #update de waarde van de database
print("database: ",database)   # print de database dictionary

standaard = {                          # standaard week waarden
    "Dinsdag" : {
      "Boiler" : 0,
      "Fornuis" : 0,
      "Lichten" : 0,
      "Vaatwas" : 0
    },
    "Donderdag" : {
      "Boiler" : 0,
      "Fornuis" : 0,
      "Lichten" : 0,
      "Vaatwas" : 0
    },
    "Maandag" : {
      "Boiler" : 0,
      "Fornuis" : 0,
      "Lichten" : 0,
      "Vaatwas" : 0
    },
    "Vrijdag" : {
      "Boiler" : 0,
      "Fornuis" : 0,
      "Lichten" : 0,
      "Vaatwas" : 0
    },
    "Woensdag" : {
      "Boiler" : 0,
      "Fornuis" : 0,
      "Lichten" : 0,
      "Vaatwas" : 0
    },
    "Zaterdag" : {
      "Boiler" : 0,
      "Fornuis" : 0,
      "Lichten" : 0,
      "Vaatwas" : 0
    },
    "Zondag" : {
      "Boiler" : 0,
      "Fornuis" : 0,
      "Lichten" : 0,
      "Vaatwas" : 0
    }
  }

print("standaard: ",standaard) # print de standaard dictionary
for diff in list(dictdiffer.diff(database, standaard)): # check de verschillen tussen de database en de standaard week
        verschil = diff[1]                              #zoek waar het verschil zit bv: maandag.Fornuis
        getal = diff[2]                                 #als er een verschil is haal dan de waarden op
        verandering = getal[0]                          #haal de verandering in de database af
        print(verschil)                                 #print waar het verschil zit
        print(verandering)                              #print de verandering van de database


