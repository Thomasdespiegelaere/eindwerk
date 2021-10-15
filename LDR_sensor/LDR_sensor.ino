const int LDR = A0;
int LDRwaarde = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  LDRwaarde = analogRead(LDR);
  Serial.print("LDRwaarde = ");
  Serial.print(LDRwaarde);
  Serial.println();
  delay(1000);
}
