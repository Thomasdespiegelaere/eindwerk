int pinZ = A0; // kan ook met PWM
int pinS0 = 2;
float adc_voltage = 0.0;
float in_voltage = 0.0;
int adc_value = 0;

void setup() {
  pinMode(pinS0, OUTPUT);
  pinMode(pinZ, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(pinS0, LOW);
  digitalWrite(pinS1, LOW);
  digitalWrite(pinS2, LOW);
  Serial.print("Y0 = ");
  Serial.print(analogRead(pinZ));
  delay(1000);
  digitalWrite(pinS0, LOW);
  Serial.print(" / ");
  Serial.print("Y1 = ");
  Serial.print(analogRead(pinZ));
  Serial.println();
  delay(1000);
}
