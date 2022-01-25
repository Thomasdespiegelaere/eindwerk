#include <EEPROM.h>

bool Zondag_Vaatwas = true;
bool test = true;
void setup() {     
  Serial.begin(9600);
  
}

void loop() {
  Zondag_Vaatwas = false;
  EEPROM.put(0, Zondag_Vaatwas);
  delay(1000);
  EEPROM.get(0, test);
  delay(1000);
  Serial.println(test);
  
}
