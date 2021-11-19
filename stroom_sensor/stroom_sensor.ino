const int analogIn = A0;
const int Mosfet = 3;
int mVperAmp = 100; 
int RawValue= 0; 
int ACSoffset = 2500; 
float Voltage = 0; 
float Amps = 0; 
float samples = 1000;
float som_samples = 0;
float gem_ams = 0;

void setup(){
  
pinMode(3, OUTPUT);
Serial.begin(9600);
}
void loop(){
  
analogWrite(Mosfet, 255); // stuur de ledstrip aan

som_samples = 0; //zet het totaal weer naar nul
for (int k = 0; k < samples;){   // zet k naar nul en vraagt of k kleiner is dan samples

  RawValue = analogRead(analogIn);
  Voltage = (RawValue / 1024.0) * 5000; // zorgt dat het naar mV input word omgezet
  Amps = ((Voltage - ACSoffset) / mVperAmp); //formule om de foutcalculatie er uit te halen
  som_samples = som_samples + Amps; //voegt nieuwe meting toe aan totaal
  k = k + 1; // verhoogt k met 1
  delay(1);
  }
  
gem_ams = som_samples / samples;
Serial.print("Raw Value = " ); // toont waarde zoals je krijgt
Serial.print(RawValue);
Serial.print("\t mV = "); // toont de gemeten spanning aan de ingang
Serial.print(Voltage,3); // zorgt dat er drie cijcers na de komma staat
Serial.print("\t Amps = "); // toont hoeveel stroom er vloeit
Serial.print(Amps,3); // zorgt dat er 3 cijfers na de komma zijn
Serial.print("\t gemiddelde = "); //print de gemiddelde waarde
Serial.println(gem_ams,3); // zorgt dat er 3 cijfers na de komma zijn
delay(1000); // wacht 1 seconde
}
