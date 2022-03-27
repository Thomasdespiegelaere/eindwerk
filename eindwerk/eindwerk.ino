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

String Read = "";           //communicatie raspberry pi arduino en database
String Dag_Ver = "";

int pinA0 = A0;            //spanningsensor batterij
float adc_voltage_batt = 0.0;
float batt_voltage = 0.0;
int adc_value_batt = 0;
int batterij_level = 0;    

const int pinA1 = A1;     //spanningsensor zon
float adc_voltage_zon = 0.0;
float zon_voltage = 0.0;
int adc_value_zon = 0;

const int analogIn = A2;  //stroomsensor variabelen 
int RawValue= 0; 
float Voltage = 0; 
float Amps = 0; 
float som_samples = 0;
float gem_ams = 0;

bool var = true;

const int pinZ_1 = 3; 
const int pinS0_1 = 2;
const int pinS1_1 = 4;

const int pinZ_2 = 5; 
const int pinS0_2 = 8;
const int pinS1_2 = 7;

const int pinZ_3 = 6; 
const int pinS0_3 = 10;
const int pinS1_3 = 11;

const int pinZ_4 = 9; 
const int pinS0_4 = 12;
const int pinS1_4 = 13;

const int Mosfet_opladen = A3;

unsigned long tijd;
float uur;
float dag = 0.0;

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

  EEPROM.get(29, batterij_level);

  pinMode(pinZ_1, OUTPUT);
  pinMode(pinS0_1, OUTPUT);
  pinMode(pinS1_1, OUTPUT);

  pinMode(pinZ_2, OUTPUT);
  pinMode(pinS0_2, OUTPUT);
  pinMode(pinS1_2, OUTPUT);

  pinMode(pinZ_3, OUTPUT);
  pinMode(pinS0_3, OUTPUT);
  pinMode(pinS1_3, OUTPUT);

  pinMode(pinZ_4, OUTPUT);
  pinMode(pinS0_4, OUTPUT);
  pinMode(pinS1_4, OUTPUT);
}

void loop() {
  Weekplanning(); 
  datum();
  batterijspanning();
  spanningzon();
  stroomsensor(); 
  if (zon_voltage > 12 && batterij_level < 50){
    if (int(dag) == 1) { // dinsdag selectie
      for (int x = 0; x < 4;) {          // doorloopt de loop 4 keer 
        if (x == 0){
          if (Dinsdag_Boiler == true) {
            if (uur >= 7.0 && uur <= 23.0 ){
              zon_Boiler(); 
              }                 
                                   
            }
         }
        else if (x == 1) {
          if (Dinsdag_Fornuis == true) { 
            if (uur >= 18.0 && uur <= 20.0 ){
              zon_Fornuis();
              }            
            }
         }
        else if (x == 2) {
          if (Dinsdag_Lichten == true) {
            if (uur >= 7.0 && uur <= 23.0 ){
              zon_Lichten();
              }            
            }
         }
        else if (x == 3){
          if (Dinsdag_Vaatwas == true) {
            zon_Vaatwas();            
            }
         }
        x = x + 1;
       }
      }
    else if (int(dag) == 3) {      
      if (Donderdag_Boiler == true) {
        
        }
      else if (Donderdag_Fornuis == true) {
        
        } 
      else if (Donderdag_Lichten == true) {
        
        }
      else if (Donderdag_Vaatwas == true) {
        
        }
      }
    else if (int(dag) == 0) { 
      if (Maandag_Boiler == true) {
        
        }
      else if (Maandag_Fornuis == true) {
        
        } 
      else if (Maandag_Lichten == true) {
        
        }
      else if (Maandag_Vaatwas == true) {
        
        }
      }  
    else if (int(dag) == 4) { 
      if (Vrijdag_Boiler == true) {
        
        }
      else if (Vrijdag_Fornuis == true) {
        
        } 
      else if (Vrijdag_Lichten == true) {
       
        }
      else if (Vrijdag_Vaatwas == true) {
        
        }
       }
    else if (int(dag) == 2) { 
      if (Woensdag_Boiler == true) {
        
        }
      else if (Woensdag_Fornuis == true) {
        
        } 
      else if (Woensdag_Lichten == true) {
        
        }
      else if (Woensdag_Vaatwas == true) {
        
        }
      }
    else if (int(dag) == 5) { 
      if (Zaterdag_Boiler == true) {
        
        }
      else if (Zaterdag_Fornuis == true) {
        
        } 
      else if (Zaterdag_Lichten == true) {
        
        }
      else if (Zaterdag_Vaatwas == true) {
        
        }
      }
    else if (int(dag) == 6) { 
      if (Zondag_Boiler == true) {
        
        }
      else if (Zondag_Fornuis == true) {
        
        } 
      else if (Zondag_Lichten == true) {
        
        }
      else if (Zondag_Vaatwas == true) {
        
        }
      }
    }
  if (zon_voltage < 12 && batterij_level > 50){
    if (Dinsdag_Boiler == true) {
                  
      }
    else if (Dinsdag_Fornuis == true) {
      
      }
    else if (Dinsdag_Lichten == true) {
      
      }
    else if (Dinsdag_Vaatwas == true) {
      
      }
    else if (Donderdag_Boiler == true) {
      
      }
    else if (Donderdag_Fornuis == true) {
      
      } 
    else if (Donderdag_Lichten == true) {
      
      }
    else if (Donderdag_Vaatwas == true) {
      
      }
    else if (Maandag_Boiler == true) {
      
      }
    else if (Maandag_Fornuis == true) {
      
      } 
    else if (Maandag_Lichten == true) {
      
      }
    else if (Maandag_Vaatwas == true) {
      
      }  
     else if (Vrijdag_Boiler == true) {
      
      }
    else if (Vrijdag_Fornuis == true) {
      
      } 
    else if (Vrijdag_Lichten == true) {
      
      }
    else if (Vrijdag_Vaatwas == true) {
      
      }
    else if (Woensdag_Boiler == true) {
      
      }
    else if (Woensdag_Fornuis == true) {
      
      } 
    else if (Woensdag_Lichten == true) {
      
      }
    else if (Woensdag_Vaatwas == true) {
      
      }
    else if (Zaterdag_Boiler == true) {
      
      }
    else if (Zaterdag_Fornuis == true) {
      
      } 
    else if (Zaterdag_Lichten == true) {
      
      }
    else if (Zaterdag_Vaatwas == true) {
      
      }
    else if (Zondag_Boiler == true) {
      
      }
    else if (Zondag_Fornuis == true) {
      
      } 
    else if (Zondag_Lichten == true) {
      
      }
    else if (Zondag_Vaatwas == true) {
      
      }    
    }
  if (zon_voltage > 12 && batterij_level < 50){
    if (Dinsdag_Boiler == true) {
                  
      }
    else if (Dinsdag_Fornuis == true) {
      
      }
    else if (Dinsdag_Lichten == true) {
      
      }
    else if (Dinsdag_Vaatwas == true) {
      
      }
    else if (Donderdag_Boiler == true) {
      
      }
    else if (Donderdag_Fornuis == true) {
      
      } 
    else if (Donderdag_Lichten == true) {
      
      }
    else if (Donderdag_Vaatwas == true) {
      
      }
    else if (Maandag_Boiler == true) {
      
      }
    else if (Maandag_Fornuis == true) {
      
      } 
    else if (Maandag_Lichten == true) {
      
      }
    else if (Maandag_Vaatwas == true) {
      
      }  
     else if (Vrijdag_Boiler == true) {
      
      }
    else if (Vrijdag_Fornuis == true) {
      
      } 
    else if (Vrijdag_Lichten == true) {
      
      }
    else if (Vrijdag_Vaatwas == true) {
      
      }
    else if (Woensdag_Boiler == true) {
      
      }
    else if (Woensdag_Fornuis == true) {
      
      } 
    else if (Woensdag_Lichten == true) {
      
      }
    else if (Woensdag_Vaatwas == true) {
      
      }
    else if (Zaterdag_Boiler == true) {
      
      }
    else if (Zaterdag_Fornuis == true) {
      
      } 
    else if (Zaterdag_Lichten == true) {
      
      }
    else if (Zaterdag_Vaatwas == true) {
      
      }
    else if (Zondag_Boiler == true) {
      
      }
    else if (Zondag_Fornuis == true) {
      
      } 
    else if (Zondag_Lichten == true) {
      
      }
    else if (Zondag_Vaatwas == true) {
      
      }    
    }   
  //opladen_batterij();
  
}

void Weekplanning() {
    var = true;
    while (var == true){
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
    }
    else if (Dag_Ver == "normale weekplanning") {
      reset = true;
      EEPROM.put(28, reset);
      var = false;         
    }else{
     delay(1000);
     var = false;    
    }
  }
}

void stroomsensor(){

som_samples = 0; //zet het totaal weer naar nul
for (int k = 0; k < 100;){   // zet k naar nul en vraagt of k kleiner is dan samples

  RawValue = analogRead(analogIn);
  Voltage = (RawValue / 1023.0) * 5000; // zorgt dat het naar mV input word omgezet
  Amps = ((Voltage - 2500) / 100); //formule om de foutcalculatie er uit te halen
  som_samples = som_samples + Amps; //voegt nieuwe meting toe aan het totaal
  k = k + 1; // verhoogt k met 1
  delay(1); //wacht 1 miliseconde
  }
  
gem_ams = som_samples / 100; //neemt het gemiddelde door het totaal van de metingen te delen door 100
delay(1000); // wacht 1 seconde
}

void spanningzon() {
  adc_value_zon = analogRead(pinA1);
  adc_voltage_zon  = (adc_value_zon * 5.0 ) / 1023.0;  
  zon_voltage = (adc_voltage_zon / 0.2) + 0.17 ;
  delay(1000);
  }

void batterijspanning() {
  adc_value_batt = analogRead(pinA0);
  adc_voltage_batt  = (adc_value_batt * 5.0 ) / 1023.0;  
  batt_voltage = (adc_voltage_batt / 0.2) + 0.17 ;
  delay(500);
  if (batt_voltage >= 12.70) {
    batterij_level = 100;         
    }
  else if (12.64 <= batt_voltage && batt_voltage <= 12.70) {
    batterij_level = 95;
    }
  else if (12.58 <= batt_voltage && batt_voltage <= 12.64) {
    batterij_level = 90;
    }
  else if (12.52 <= batt_voltage && batt_voltage <= 12.58) {
    batterij_level = 85;
    }
  else if (12.46 <= batt_voltage && batt_voltage <= 12.52) {
    batterij_level = 80;
    }
  else if (12.40 <= batt_voltage && batt_voltage <= 12.46) {
    batterij_level = 75;
    }
  else if (12.36 <= batt_voltage && batt_voltage <= 12.40) {
    batterij_level = 70;
    }
  else if (12.32 <= batt_voltage && batt_voltage <= 12.36) {
    batterij_level = 65;
    }
  else if (12.28 <= batt_voltage && batt_voltage <= 12.32) {
    batterij_level = 60;
    }
  else if (12.24 <= batt_voltage && batt_voltage <= 12.28) {
    batterij_level = 55;
    }
  else if (12.20 <= batt_voltage && batt_voltage <= 12.24) {
    batterij_level = 50;
    }
  else if (12.16 <= batt_voltage && batt_voltage <= 12.20) {
    batterij_level = 45;
    }
  else if (12.12 <= batt_voltage && batt_voltage <= 12.16) {
    batterij_level = 40;
    }
  else if (12.08 <= batt_voltage && batt_voltage <= 12.12) {
    batterij_level = 35;
    }
  else if (12.04 <= batt_voltage && batt_voltage <= 12.08) {
    batterij_level = 30;
    }
  else if (12.00 <= batt_voltage && batt_voltage <= 12.04) {
    batterij_level = 25;
    }
  else if (11.98 <= batt_voltage && batt_voltage <= 12.00) {
    batterij_level = 20;
    }
  else if (11.96 <= batt_voltage && batt_voltage <= 11.98) {
    batterij_level = 15;
    }
  else if (11.94 <= batt_voltage && batt_voltage <= 11.96) {
    batterij_level = 10;
    }
  else if (11.92 <= batt_voltage && batt_voltage <= 11.94) {
    batterij_level = 5;
    }
  else if (batt_voltage < 11.92) {
    batterij_level = 0;
    }
  delay(1000);
  EEPROM.put(29, batterij_level);
}

void opladen_batterij() {  
  spanningzon();
  batterijspanning();
  if (zon_voltage > batt_voltage){   
    analogWrite(Mosfet_opladen, 255);
    }
  else if (zon_voltage < batt_voltage){
      analogWrite(Mosfet_opladen, 0);
   }
  delay(1);
}

void zon_Boiler() {
  digitalWrite(pinS0_1, LOW);
  digitalWrite(pinS1_1, HIGH);
  }

void zon_Fornuis() {
  digitalWrite(pinS0_4, LOW);
  digitalWrite(pinS1_4, HIGH);
  }

void zon_Lichten() {
  digitalWrite(pinS0_3, LOW);
  digitalWrite(pinS1_3, HIGH);
  }

void zon_Vaatwas() {
  digitalWrite(pinS0_2, LOW);
  digitalWrite(pinS1_2, HIGH);
  }

void batt_Boiler() {
  digitalWrite(pinS0_1, LOW);
  digitalWrite(pinS1_1, LOW);
  }

void batt_Fornuis() {
  digitalWrite(pinS0_4, LOW);
  digitalWrite(pinS1_4, LOW);
  }

void batt_Lichten() {
  digitalWrite(pinS0_3, LOW);
  digitalWrite(pinS1_3, LOW);
  }

void batt_Vaatwas() {
  digitalWrite(pinS0_2, LOW);
  digitalWrite(pinS1_2, LOW);
  }

void net_Boiler() {
  digitalWrite(pinS0_1, HIGH);
  digitalWrite(pinS1_1, LOW);
  }

void net_Fornuis() {
  digitalWrite(pinS0_4, HIGH);
  digitalWrite(pinS1_4, LOW);
  }

void net_Lichten() {
  digitalWrite(pinS0_3, HIGH);
  digitalWrite(pinS1_3, LOW);
  }

void net_Vaatwas() {
  digitalWrite(pinS0_2, HIGH);
  digitalWrite(pinS1_2, LOW);
  }
  
void uit_Boiler() {
  digitalWrite(pinS0_1, HIGH);
  digitalWrite(pinS1_1, HIGH);
  }

void uit_Fornuis() {
  digitalWrite(pinS0_4, HIGH);
  digitalWrite(pinS1_4, HIGH);
  }

void uit_Lichten() {
  digitalWrite(pinS0_3, HIGH);
  digitalWrite(pinS1_3, HIGH);
  }

void uit_Vaatwas() {
  digitalWrite(pinS0_2, HIGH);
  digitalWrite(pinS1_2, HIGH);
  }
  
void datum() {
    tijd = millis();
    uur = tijd / 2500;
    if (uur >= 24.0){
      uur = uur - 24.0;
      dag = dag + 1.0;
      if (dag > 7.0) {
        dag = 0.0;
        }
      }         
    }
