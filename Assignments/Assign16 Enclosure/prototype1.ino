//variables for debounce function(if needed)
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
int lastButtonState=HIGH;
int buttonState=HIGH;

//initialize variable for score
int score=0;

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
  //pin for incorrect and loss of game
  pinMode(1,OUTPUT);
  //INPUT TO SEE IF RIGHT BUTTON IS PRESSED
  //task 1
  pinMode(9, INPUT_PULLUP);
  //TASK 2
  pinMode(10, INPUT_PULLUP);
  //task 3
  pinMode(0, INPUT_PULLUP);
  //used to pull random value
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  while(1){
  //set all outputs to low
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(3, LOW);
  digitalWrite(1, LOW);
  //5 seconds to make deciscion
  unsigned long event=5000;
  //intiailze variable for previous time
  unsigned long previousTime;
  //variable to hold button pressed by user
  int state=0;
  int correct_answer=randomNum();
    //code to turn on correct LED light for task
    if(correct_answer==1)
      digitalWrite(8, HIGH);
    else if(correct_answer==2)
      digitalWrite(7, HIGH);
    else
      digitalWrite(6, HIGH);


    //wati for response or 5 seconds
    previousTime=millis();
    while((millis()-previousTime)<=event){
    //check to see if correct button was pressed
    if(!digitalRead(9)){
      state=1;
      break;
    }
    else if(!digitalRead(10)){
      state=2;
      break;
    }
    else if(!digitalRead(0)){
      state=3;
      break;
    }
    //this means no input was made
    else if((millis()-previousTime)>=event){
      digitalWrite(1,HIGH);
      //exit code and hold state
      exit(1);
    }
   }

    //now check to see if correct button had been pressed
    if(state==correct_answer){
      //turn on correct light
      digitalWrite(3,HIGH);
      delay(3000);
    }
    else{
      //turn on incorrect light and end game
      digitalWrite(1, HIGH);
      exit(1);
    }
   
  }
}

//random task generator
int randomNum(){
  int randomNumber= random(1,4);
  return randomNumber;
}


