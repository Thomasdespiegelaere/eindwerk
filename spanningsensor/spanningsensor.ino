int pinA0 = A0; 
float adc_voltage = 0.0;
float in_voltage = 0.0;
int adc_value = 0;
int batterij_level = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  adc_value = analogRead(pinA0);
  adc_voltage  = (adc_value * 5.0 ) / 1023.0;  
  in_voltage = (adc_voltage / 0.2) + 0.17 ;
  delay(500);
  Serial.println(in_voltage);
  if (in_voltage >= 12.70) {
    batterij_level = 100;         
    }
  else if (12.64 <= in_voltage && in_voltage <= 12.70) {
    batterij_level = 95;
    }
  else if (12.58 <= in_voltage && in_voltage <= 12.64) {
    batterij_level = 90;
    }
  else if (12.52 <= in_voltage && in_voltage <= 12.58) {
    batterij_level = 85;
    }
  else if (12.46 <= in_voltage && in_voltage <= 12.52) {
    batterij_level = 80;
    }
  else if (12.40 <= in_voltage && in_voltage <= 12.46) {
    batterij_level = 75;
    }
  else if (12.36 <= in_voltage && in_voltage <= 12.40) {
    batterij_level = 70;
    }
  else if (12.32 <= in_voltage && in_voltage <= 12.36) {
    batterij_level = 65;
    }
  else if (12.28 <= in_voltage && in_voltage <= 12.32) {
    batterij_level = 60;
    }
  else if (12.24 <= in_voltage && in_voltage <= 12.28) {
    batterij_level = 55;
    }
  else if (12.20 <= in_voltage && in_voltage <= 12.24) {
    batterij_level = 50;
    }
  else if (12.16 <= in_voltage && in_voltage <= 12.20) {
    batterij_level = 45;
    }
  else if (12.12 <= in_voltage && in_voltage <= 12.16) {
    batterij_level = 40;
    }
  else if (12.08 <= in_voltage && in_voltage <= 12.12) {
    batterij_level = 35;
    }
  else if (12.04 <= in_voltage && in_voltage <= 12.08) {
    batterij_level = 30;
    }
  else if (12.00 <= in_voltage && in_voltage <= 12.04) {
    batterij_level = 25;
    }
  else if (11.98 <= in_voltage && in_voltage <= 12.00) {
    batterij_level = 20;
    }
  else if (11.96 <= in_voltage && in_voltage <= 11.98) {
    batterij_level = 15;
    }
  else if (11.94 <= in_voltage && in_voltage <= 11.96) {
    batterij_level = 10;
    }
  else if (11.92 <= in_voltage && in_voltage <= 11.94) {
    batterij_level = 5;
    }
  else if (in_voltage < 11.92) {
    batterij_level = 0;
    }
  Serial.println(batterij_level);
  delay(1000);
}
