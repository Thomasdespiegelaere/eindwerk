const int Boiler_zon = 2; 
const int Boiler_net = 3;
const int Boiler_batt = 4;

const int Vaatwas_zon = 9; 
const int Vaatwas_net = 10;
const int Vaatwas_batt = 11;

const int Lichten_zon = 5; 
const int Lichten_net = 6;
const int Lichten_batt = 7;

const int Fornuis_zon = 8; 
const int Fornuis_net = 12;
const int Fornuis_batt = 13;

const int Mosfet_opladen = A3;

void setup() {

  pinMode(Boiler_zon, OUTPUT);
  pinMode(Boiler_net, OUTPUT);
  pinMode(Boiler_batt, OUTPUT);

  pinMode(Vaatwas_zon, OUTPUT);
  pinMode(Vaatwas_net, OUTPUT);
  pinMode(Vaatwas_batt, OUTPUT);

  pinMode(Lichten_zon, OUTPUT);
  pinMode(Lichten_net, OUTPUT);
  pinMode(Lichten_batt, OUTPUT);

  pinMode(Fornuis_zon, OUTPUT);
  pinMode(Fornuis_net, OUTPUT);
  pinMode(Fornuis_batt, OUTPUT);

  pinMode(Mosfet_opladen, OUTPUT);

}

void loop() {
  digitalWrite(Boiler_zon, HIGH);
  digitalWrite(Fornuis_zon, HIGH);
  digitalWrite(Lichten_zon, HIGH);
  analogWrite(Vaatwas_zon, 20);
  digitalWrite(Boiler_batt, HIGH);
  digitalWrite(Fornuis_batt, HIGH);
  digitalWrite(Lichten_batt, HIGH);
  analogWrite(Vaatwas_batt, 20);
  digitalWrite(Boiler_net, HIGH);
  digitalWrite(Fornuis_net, HIGH);
  digitalWrite(Lichten_net, HIGH);
  analogWrite(Vaatwas_net, 20);
  digitalWrite(Mosfet_opladen, HIGH);
}
