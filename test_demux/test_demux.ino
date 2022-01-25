int pinZ = A0; // kan ook met PWM
int pinS0 = 2;

void setup() {
  pinMode(pinS0, OUTPUT);
  pinMode(pinZ, OUTPUT);
}

void loop() {
  digitalWrite(pinS0, LOW);
  digitalWrite(pinZ, 255);
  delay(5000);
  digitalWrite(pinS0, HIGH);
  digitalWrite(pinZ, 255);
  delay(5000);
}
