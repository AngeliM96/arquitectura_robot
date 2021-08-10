int ledR_pin = 4;
int ledG_pin = 3;
int ledB_pin = 2;

void rgb(char color);

void setup() {
  pinMode(ledR_pin, OUTPUT);
  pinMode(ledG_pin, OUTPUT);
  pinMode(ledB_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  rgb('r');
  delay(1000);
  rgb('g');
  delay(1000);
  rgb('b');
  delay(1000);
  rgb('a');
  delay(1000);
}

void rgb(char color) {
  switch (color) {
    case 'r': //red
      digitalWrite(ledR_pin, LOW);
      digitalWrite(ledG_pin, HIGH);
      digitalWrite(ledB_pin, HIGH);
      break;
    case 'g': //green
      digitalWrite(ledR_pin, HIGH);
      digitalWrite(ledG_pin, LOW);
      digitalWrite(ledB_pin, HIGH);
      break;
    case 'y': //yellow
      digitalWrite(ledR_pin, LOW);
      digitalWrite(ledG_pin, LOW);
      digitalWrite(ledB_pin, HIGH);
      break;
    case 'b': //blue
      digitalWrite(ledR_pin, HIGH);
      digitalWrite(ledG_pin, HIGH);
      digitalWrite(ledB_pin, LOW);
      break;
    case 'a': //apagado
      digitalWrite(ledR_pin, HIGH);
      digitalWrite(ledG_pin, HIGH);
      digitalWrite(ledB_pin, HIGH);
      break;
  }
}
