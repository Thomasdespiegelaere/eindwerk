const int pinZ_1 = 3; 
const int pinS0_1 = 2;
const int pinS1_1 = 4;

const int pinZ_2 = 5; 
const int pinS0_2 = 8;
const int pinS1_2 = 7;

const int pinZ_3 = 6; 
const int pinS0_3 = 10;
const int pinS1_3 = 11;

const int pinZ_4 = 9; 
const int pinS0_4 = 12;
const int pinS1_4 = 13;

void setup() {
  pinMode(pinZ_1, OUTPUT);
  pinMode(pinS0_1, OUTPUT);
  pinMode(pinS1_1, OUTPUT);

  pinMode(pinZ_2, OUTPUT);
  pinMode(pinS0_2, OUTPUT);
  pinMode(pinS1_2, OUTPUT);

  pinMode(pinZ_3, OUTPUT);
  pinMode(pinS0_3, OUTPUT);
  pinMode(pinS1_3, OUTPUT);

  pinMode(pinZ_4, OUTPUT);
  pinMode(pinS0_4, OUTPUT);
  pinMode(pinS1_4, OUTPUT);  

}

void loop() {
  digitalWrite(pinS0_1, LOW);
  digitalWrite(pinS1_1, HIGH);
  digitalWrite(pinZ_1, 255);

  digitalWrite(pinS0_2, LOW);
  digitalWrite(pinS1_2, HIGH);
  digitalWrite(pinZ_2, 255);

  digitalWrite(pinS0_3, LOW);
  digitalWrite(pinS1_3, HIGH);
  analogWrite(pinZ_3, 255);

  digitalWrite(pinS0_4, HIGH);
  digitalWrite(pinS1_4, LOW);
  digitalWrite(pinZ_4, 255);
}
