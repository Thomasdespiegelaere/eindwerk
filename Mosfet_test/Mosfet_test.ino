const int Mosfet = 3;

void setup() {
  pinMode(3, OUTPUT);
}

void loop() {
  analogWrite(Mosfet, 255);
}
