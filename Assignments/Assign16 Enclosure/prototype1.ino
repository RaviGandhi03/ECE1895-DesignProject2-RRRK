void setup() {
  // put your setup code here, to run once:
  //pin for task1 selection
  pinMode(8, OUTPUT);
  //pin for task 2 selection
  pinMode(7, OUTPUT);
  //pin for task 3 selection
  pinMode(6, OUTPUT);
  //pins for correct LED light
  pinMode(3, OUTPUT);
  //INPUT TO SEE IF RIGHT BUTTON IS PRESSED
  //task 1
  pinMode(9, INPUT_PULLUP);
  //TASK 2
  pinMode(10, INPUT_PULLUP);
  //task 3
  pinMode(0, INPUT_PULLUP);

  randomSeed(analogRead(0));
  unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
  unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
}

void loop() {
  // put your main code here, to run repeatedly:
  while(1){
  //set all outputs to low
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(3, LOW);
  int input_answer;
  int score=0;
    int correct_answer=command();
    //code to turn on correct LED light for task
    if(correct_answer==1)
      digitalWrite(8, HIGH);
    else if(correct_answer==2)
      digitalWrite(7, HIGH);
    else
      digitalWrite(6, HIGH);

    //delay for 3 seconds or response
    int wait=0;
    while(wait<3000){
      delay(100);
     if((digitalRead(6)==1 && digitalRead(0)==0) || (digitalRead(7)==1 && digitalRead(10)==0) || (digitalRead(8)==1 && digitalRead(9)==0)){
      digitalWrite(3, HIGH);
      delay(2000);
      score++;
      break;
     }
     else if((digitalRead(6)==0 && digitalRead(0)==1) || (digitalRead(7)==0 && digitalRead(10)==1) || (digitalRead(8)==0 && digitalRead(9)==1)){
      delay(2000);
      break;
     }
     else{
      delay(10);
      wait++;
     }
    }
    
  }
}

int command(){
  int randomNumber= random(1,4);
  return randomNumber;
}
