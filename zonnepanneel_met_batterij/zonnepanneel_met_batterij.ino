const int analogIn = A0;
const int Mosfet = 3;
const int Mosfet_bat = 5;
int mVperAmp = 100; 
int RawValue= 0; 
int ACSoffset = 2500; 
float Voltage = 0; 
float Amps = 0; 
float samples = 100;
float som_samples = 0;
float gem_ams = 0;

const int pinA1 = A1; 
float adc_voltage = 0.0;
float zon_voltage = 0.0;
int adc_value = 0;

const int pinA2 = A2; 
float adc_voltage2 = 0.0;
float batt_voltage = 0.0;
int adc_value2 = 0;
int batterij_level = 0;

void setup(){
  pinMode(3, OUTPUT);    //defineerd pin 3 als uitgang
  pinMode(5, OUTPUT);    //defineerd pin 5 als uitgang
  Serial.begin(9600);    //start de seriele communicatie en stelt deze in op 9600 baud
  analogWrite(3, 0);
  analogWrite(5, 0);
}

void loop() {  
  stroomsensor();
  spanningzon();
  batterij();
  if (zon_voltage > batt_voltage){   
    analogWrite(3, 255);
    analogWrite(5, 255);
    }
  else if (zon_voltage < batt_voltage){
      analogWrite(3, 0);
      analogWrite(5, 0);
   }
  }
void stroomsensor(){

som_samples = 0; //zet het totaal weer naar nul
for (int k = 0; k < samples;){   // zet k naar nul en vraagt of k kleiner is dan samples

  RawValue = analogRead(analogIn);
  Voltage = (RawValue / 1023.0) * 5000; // zorgt dat het naar mV input word omgezet
  Amps = ((Voltage - ACSoffset) / mVperAmp); //formule om de foutcalculatie er uit te halen
  som_samples = som_samples + Amps; //voegt nieuwe meting toe aan het totaal
  k = k + 1; // verhoogt k met 1
  delay(1); //wacht 1 miliseconde
  }
  
gem_ams = som_samples / samples; //neemt het gemiddelde door het totaal van de metingen te delen door 100
Serial.println(gem_ams,3); // zorgt dat er 3 cijfers na de komma zijn
delay(1000); // wacht 1 seconde
}

void spanningzon() {
  adc_value = analogRead(pinA1);
  adc_voltage  = (adc_value * 5.0 ) / 1023.0;  
  zon_voltage = (adc_voltage / 0.2) + 0.17 ;
  Serial.println(zon_voltage);
  delay(1000);
  }

void batterij() {
  adc_value2 = analogRead(pinA2);
  adc_voltage2  = (adc_value2 * 5.0 ) / 1023.0;  
  batt_voltage = (adc_voltage2 / 0.2) + 0.17 ;
  delay(500);
  Serial.println(batt_voltage);
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
  Serial.println(batterij_level);
  delay(1000);
}
