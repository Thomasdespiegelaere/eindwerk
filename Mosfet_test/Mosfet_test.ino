const int Mosfet = 3; //stelt pin 3 in als mosfet

void setup() {
  pinMode(3, OUTPUT); //stelt pin 3 in als uitgang
}

void loop() {
  analogWrite(Mosfet, 20); //zet de mosfet hellemaal open
}
