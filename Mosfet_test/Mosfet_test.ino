const int Mosfet = A5; //stelt pin 3 in als mosfet

void setup() {
  pinMode(Mosfet, OUTPUT); //stelt pin 3 in als uitgang
}

void loop() {
  analogWrite(Mosfet, 20); //zet de mosfet op 20 van de 255
}
