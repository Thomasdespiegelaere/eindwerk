#include <EEPROM.h>

bool Dinsdag_Boiler = true;
bool Dinsdag_Fornuis = true;
bool Dinsdag_Lichten = false;
bool Dinsdag_Vaatwas = true;

bool Donderdag_Boiler = true;
bool Donderdag_Fornuis = true;
bool Donderdag_Lichten = true;
bool Donderdag_Vaatwas = false;

bool Maandag_Boiler = false;
bool Maandag_Fornuis = true;
bool Maandag_Lichten = true;
bool Maandag_Vaatwas = true;

bool Vrijdag_Boiler = true;
bool Vrijdag_Fornuis = true;
bool Vrijdag_Lichten = true;
bool Vrijdag_Vaatwas = true;
          
bool Woensdag_Boiler = true;
bool Woensdag_Fornuis = true;
bool Woensdag_Lichten = true;
bool Woensdag_Vaatwas = true;

bool Zaterdag_Boiler = true;
bool Zaterdag_Fornuis = true;
bool Zaterdag_Lichten = true;
bool Zaterdag_Vaatwas = true;
        
bool Zondag_Boiler = true;
bool Zondag_Fornuis = true;
bool Zondag_Lichten = true;
bool Zondag_Vaatwas = true;

bool reset = false;

void setup() {
  Serial.begin(9600);
  EEPROM.get(0, Dinsdag_Boiler);
  EEPROM.get(1, Dinsdag_Fornuis);
  EEPROM.get(2, Dinsdag_Lichten);
  EEPROM.get(3, Dinsdag_Vaatwas);
  
  EEPROM.get(4, Donderdag_Boiler);
  EEPROM.get(5, Donderdag_Fornuis);
  EEPROM.get(6, Donderdag_Lichten);
  EEPROM.get(7, Donderdag_Vaatwas);
  
  EEPROM.get(8, Maandag_Boiler);
  EEPROM.get(9, Maandag_Fornuis);
  EEPROM.get(10, Maandag_Lichten);
  EEPROM.get(11, Maandag_Vaatwas);
  
  EEPROM.get(12, Vrijdag_Boiler);
  EEPROM.get(13, Vrijdag_Fornuis);
  EEPROM.get(14, Vrijdag_Lichten);
  EEPROM.get(15, Vrijdag_Vaatwas);
  
  EEPROM.get(16, Woensdag_Boiler);
  EEPROM.get(17, Woensdag_Fornuis);
  EEPROM.get(18, Woensdag_Lichten);
  EEPROM.get(19, Woensdag_Vaatwas);
  
  EEPROM.get(20, Zaterdag_Boiler);
  EEPROM.get(21, Zaterdag_Fornuis);
  EEPROM.get(22, Zaterdag_Lichten);
  EEPROM.get(23, Zaterdag_Vaatwas);
  
  EEPROM.get(24, Zondag_Boiler);
  EEPROM.get(25, Zondag_Fornuis);
  EEPROM.get(26, Zondag_Lichten);
  EEPROM.get(27, Zondag_Vaatwas);
  
  EEPROM.get(28, reset);
}

void loop() {
  

}
