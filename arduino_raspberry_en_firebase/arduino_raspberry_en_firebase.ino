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

String Read = "";
String Dag_Ver = "";

void setup() {
  Serial.begin(9600);
}

void loop() {
   
    delay(10);
    Serial.println("dagen");
    delay(10);
    Serial.println('>');
    Dag_Ver = Serial.readString();
    if (Dag_Ver == "Dinsdag.Boiler") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False") {
        Dinsdag_Boiler = false; 
        EEPROM.put(0, Dinsdag_Boiler);         
      }
      else if (Read == "True") {
        Dinsdag_Boiler = true;
        EEPROM.put(0, Dinsdag_Boiler);           
      }     
    }
    else if (Dag_Ver == "Dinsdag.Fornuis") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Dinsdag_Fornuis = false;
        EEPROM.put(1, Dinsdag_Fornuis);            
      }
      else if (Read == "True") {
        Dinsdag_Fornuis = true;
        EEPROM.put(1, Dinsdag_Fornuis);             
      }     
    }
    else if (Dag_Ver == "Dinsdag.Lichten") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Dinsdag_Lichten = false;
        EEPROM.put(2, Dinsdag_Lichten);            
      }
      else if (Read == "True") {
        Dinsdag_Lichten = true;
        EEPROM.put(2, Dinsdag_Lichten);            
      }     
    }
    else if (Dag_Ver == "Dinsdag.Vaatwas") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Dinsdag_Vaatwas = false;
        EEPROM.put(3, Dinsdag_Vaatwas);            
      }
      else if (Read == "True") {
        Dinsdag_Vaatwas = true;
        EEPROM.put(3, Dinsdag_Vaatwas);             
      }     
    }
    else if (Dag_Ver == "Donderdag.Boiler") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Donderdag_Boiler = false; 
        EEPROM.put(4, Donderdag_Boiler);           
      }
      else if (Read == "True") {
        Donderdag_Boiler = true;
        EEPROM.put(4, Donderdag_Boiler);             
      }     
    }
    else if (Dag_Ver == "Donderdag.Fornuis") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Donderdag_Fornuis = false;
        EEPROM.put(5, Donderdag_Fornuis);            
      }
      else if (Read == "True") {
        Donderdag_Fornuis = true;
        EEPROM.put(5, Donderdag_Fornuis);             
      }     
    }
    else if (Dag_Ver == "Donderdag.Lichten") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Donderdag_Lichten = false;
        EEPROM.put(6, Donderdag_Lichten);          
      }
      else if (Read == "True") {
        Donderdag_Lichten = true;
        EEPROM.put(6, Donderdag_Lichten);         
      }     
    }
    else if (Dag_Ver == "Donderdag.Vaatwas") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Donderdag_Vaatwas = false;
        EEPROM.put(7, Donderdag_Vaatwas);         
      }
      else if (Read == "True") {
        Donderdag_Vaatwas = true;  
        EEPROM.put(7, Donderdag_Vaatwas);        
      }     
    }
    else if (Dag_Ver == "Maandag.Boiler") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Maandag_Boiler = false; 
        EEPROM.put(8, Maandag_Boiler);       
      }
      else if (Read == "True") {
        Maandag_Boiler = true; 
        EEPROM.put(8, Maandag_Boiler);       
      }     
    }
    else if (Dag_Ver == "Maandag.Fornuis") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Maandag_Fornuis = false;
        EEPROM.put(9, Maandag_Fornuis);     
      }
      else if (Read == "True") {
        Maandag_Fornuis = true; 
        EEPROM.put(9, Maandag_Fornuis);            
      }     
    }
    else if (Dag_Ver == "Maandag.Lichten") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Maandag_Lichten = false;
        EEPROM.put(10, Maandag_Lichten);           
      }
      else if (Read == "True") {
        Maandag_Lichten = true;
        EEPROM.put(10, Maandag_Lichten);            
      }     
    }
    else if (Dag_Ver == "Maandag.Vaatwas") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Maandag_Vaatwas = false; 
        EEPROM.put(11, Maandag_Vaatwas);           
      }
      else if (Read == "True") {
        Maandag_Vaatwas = true;  
        EEPROM.put(11, Maandag_Vaatwas);           
      }     
    }
    else if (Dag_Ver == "Vrijdag.Boiler") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Vrijdag_Boiler = false;
        EEPROM.put(12, Vrijdag_Boiler);            
      }
      else if (Read == "True") {
        Vrijdag_Boiler = true; 
        EEPROM.put(12, Vrijdag_Boiler);            
      }     
    }
    else if (Dag_Ver == "Vrijdag.Fornuis") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Vrijdag_Fornuis = false;
        EEPROM.put(13, Vrijdag_Fornuis);           
      }
      else if (Read == "True") {
        Vrijdag_Fornuis = true;
        EEPROM.put(13, Vrijdag_Fornuis);             
      }     
    }
    else if (Dag_Ver == "Vrijdag.Lichten") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Vrijdag_Lichten = false;
        EEPROM.put(14, Vrijdag_Lichten);            
      }
      else if (Read == "True") {
        Vrijdag_Lichten = true;
        EEPROM.put(14, Vrijdag_Lichten);           
      }     
    }
    else if (Dag_Ver == "Vrijdag.Vaatwas") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Vrijdag_Vaatwas = false;
        EEPROM.put(15, Vrijdag_Vaatwas);           
      }
      else if (Read == "True") {
        Vrijdag_Vaatwas = true;
        EEPROM.put(15, Vrijdag_Vaatwas);            
      }     
    }
    else if (Dag_Ver == "Woensdag.Boiler") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Woensdag_Boiler = false;   
        EEPROM.put(16, Woensdag_Boiler);       
      }
      else if (Read == "True") {
        Woensdag_Boiler = true; 
        EEPROM.put(16, Woensdag_Boiler);           
      }     
    }
    else if (Dag_Ver == "Woensdag.Fornuis") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Woensdag_Fornuis = false;
        EEPROM.put(17, Woensdag_Fornuis);            
      }
      else if (Read == "True") {
        Woensdag_Fornuis = true;
        EEPROM.put(17, Woensdag_Fornuis);            
      }     
    }
    else if (Dag_Ver == "Woensdag.Lichten") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Woensdag_Lichten = false;
        EEPROM.put(18, Woensdag_Lichten);           
      }
      else if (Read == "True") {
        Woensdag_Lichten = true;
        EEPROM.put(18, Woensdag_Lichten);             
      }     
    }
    else if (Dag_Ver == "Woensdag.Vaatwas") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Woensdag_Vaatwas = false;
        EEPROM.put(19, Woensdag_Vaatwas);           
      }
      else if (Read == "True") {
        Woensdag_Vaatwas = true; 
        EEPROM.put(19, Woensdag_Vaatwas);            
      }     
    }
    else if (Dag_Ver == "Zaterdag.Boiler") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Zaterdag_Boiler = false;
        EEPROM.put(20, Zaterdag_Boiler);           
      }
      else if (Read == "True") {
        Zaterdag_Boiler = true;
        EEPROM.put(20, Zaterdag_Boiler);            
      }     
    }
    else if (Dag_Ver == "Zaterdag.Fornuis") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Zaterdag_Fornuis = false;
        EEPROM.put(21, Zaterdag_Fornuis);            
      }
      else if (Read == "True") {
        Zaterdag_Fornuis = true;
        EEPROM.put(21, Zaterdag_Fornuis);            
      }     
    }
    else if (Dag_Ver == "Zaterdag.Lichten") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Zaterdag_Lichten = false;
        EEPROM.put(22, Zaterdag_Lichten);            
      }
      else if (Read == "True") {
        Zaterdag_Lichten = true;
        EEPROM.put(22, Zaterdag_Lichten);           
      }     
    }
    else if (Dag_Ver == "Zaterdag.Vaatwas") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Zaterdag_Vaatwas = false;
        EEPROM.put(23, Zaterdag_Vaatwas);            
      }
      else if (Read == "True") {
        Zaterdag_Vaatwas = true;
        EEPROM.put(23, Zaterdag_Vaatwas);             
      }     
    }
    else if (Dag_Ver == "Zondag.Boiler") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Zondag_Boiler = false;
        EEPROM.put(24, Zondag_Boiler);            
      }
      else if (Read == "True") {
        Zondag_Boiler = true;
        EEPROM.put(24, Zondag_Boiler);             
      }     
    }
    else if (Dag_Ver == "Zondag.Fornuis") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Zondag_Fornuis = false;
        EEPROM.put(25, Zondag_Fornuis);            
      }
      else if (Read == "True") {
        Zondag_Fornuis = true;
        EEPROM.put(25, Zondag_Fornuis);          
      }     
    }
    else if (Dag_Ver == "Zondag.Lichten") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Zondag_Lichten = false;
        EEPROM.put(26, Zondag_Lichten);           
      }
      else if (Read == "True") {
        Zondag_Lichten = true;
        EEPROM.put(26, Zondag_Lichten);            
      }     
    }
    else if (Dag_Ver == "Zondag.Vaatwas") {
      Serial.println('>');
      Read = Serial.readString();
      if (Read == "False" ) {
        Zondag_Vaatwas = false;
        EEPROM.put(27, Zondag_Vaatwas);            
      }
      else if (Read == "True") {
        Zondag_Vaatwas = true;
        EEPROM.put(27, Zondag_Vaatwas);             
      }     
    }else{
     delay(1000);
     Serial.println(Dinsdag_Boiler);
     Serial.println(Donderdag_Fornuis);
     Serial.println(Maandag_Fornuis);
     Serial.println(Zaterdag_Lichten);
     Serial.println(Dinsdag_Lichten);
     Serial.println(Donderdag_Vaatwas);
     Serial.println(Maandag_Boiler);
     //exit(0);    
    }
}

