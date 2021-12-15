const int LDR = A0;
int LDRwaarde = 0;

void setup() {
  Serial.begin(9600); //start de seriele communicatie en zet deze op 9600 baud
}

void loop() {
  LDRwaarde = analogRead(LDR); //leest de ldr waarde
  Serial.print("LDRwaarde = ");
  Serial.print(LDRwaarde); //print de ldr waarde
  Serial.println(); // gaat naar de volgende lijn
  delay(1000);  //wacht 1 seconde
}
