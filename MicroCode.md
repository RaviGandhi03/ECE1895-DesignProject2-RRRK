# ECE1895-DesignProject2-RRRK
Ravi Gandhi, Reece Basehore, Ryan Hankee, Kamden Sarkey; Design Project 2 for ECE 1895 Fall 2021
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(8, OUTPUT);
  pinMode(9, INPUT_PULLUP);
}

// the loop function runs over and over again forever
void loop() {
  if (!digitalRead(9)) {
    digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);                       // wait for a second
  }
}
//Ryan
