void setup() {
  // put your setup code here, to run once:
    pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(9, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(!digitalRead(9)){
    digitalWrite(8, HIGH);
    delay(700);
    digitalWrite(8,LOW);
    delay(700);
    digitalWrite(7, HIGH);
    delay(700);
    digitalWrite(7,LOW);
    delay(700);
    digitalWrite(6, HIGH);
    delay(700);
    digitalWrite(6,LOW);
    delay(700);
  }
}
