//********DIGITAL PIN INPUTS FOR BUTTTONS ARE PULLED HIGH SO PRESSING BUTTON MAKES INPUT GO LOW
//include files for LCD display
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SD.h>



//TASK 1= BUTTON
//TASK 2=JOYSTICK
//TASK 3=ULTRASONIC SENSOR

//declare variable for LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); 
//declare variables

int buttonTask=4;//buttons
int startPin=0;

int joyX=A0; //joystick
int joyY=A1;
int sw=1;

int trig=3;//sensor
int echo=2;

int threshold=20;//ultrasonic threshold

long duration; //sensor variables
int distance;

int greenLED=6; //LED pins
int redLED=7;

//-----------------------------------------------------------------//

void setup() {
  // put your setup code here, to run once:
  //initilize lcd display
  lcd.init();
  lcd.backlight();
  //create pin input and outputs
  pinMode(joyX, OUTPUT);
  pinMode(joyY, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
  pinMode(buttonTask, INPUT_PULLUP);
  pinMode(startPin, INPUT_PULLUP);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //creat variables to keep track of score and set equal to 0 before start of each game;
  int score=0;
  //make sure all outputs are low to start
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);
  //wait to see if start button has been pressed
  while(digitalRead(startPin)){                       
    //stay here until start button is pressed
  }
  //immediately initialize score to 0 on lcd display
  displayScore(score);
  //once button is pressed play game until score reaches 100 or incorrect response
  while(score<=99){
  //set digital outputs all low
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);
  //generate a task to generate correct answer, task to be performed
  int correctTask= getRandomTask();
  //figure out how much time user will have to make correct response
  unsigned long decisionTime=getDecisionTime(score);
  //create previos time variable
  unsigned long previousTime;
  //have variable to hold user response
  int userResponse=0;
  //create code to play audio file for task to be performed
  playTaskPerform(correctTask);
  //reset time for countdown
  previousTime=millis(); = 5s
  //wait for response or answer
  while((millis()-previousTime)<=decisionTime+10){ 5s
    //check to see what buttun was pressed
    if(!digitalRead(buttonTask)){
      userResponse=1;
      break;
    }
    //joystick movement to see if joystick was moved
    else if(joystickMovement()){
      userResponse=2;
      break;
    }
    //sensor check to see how close to ultrasonic sensor
    else if(sensorCheck()){
      userResponse=3;
      break;
    }
    //no response was picked in alloted time
    else if((millis()-previousTime)>=decisionTime){
      displayEndGame();
      break;
    }
  }

  //check to see if user picked correct response
  if(userResponse==correctTask){
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("Correct");
  lcd.setCursor(7,1);
  lcd.print("!!!!!");
  delay(2000); //delay 2 seconds then display score
  score++;
  displayScore(score);
  }
  else{
    displayEndGame();
  }
  
  
  }
  //if user gets here then user has won game  notify user of winning
  congratulations();
}

//create function to generate random task
int getRandomTask(){
  //returns random task as integer 1-3
}

unsigned long getDecisionTime(int score){
  //generate time in milliseconds that user will have to make response based on score
}

//play correct audio file
void playTaskPerform(int task){
  if(task==1){
    //play task 1 audio file
  }
  else if(task==2){
    //play task 2 audio file
  }
  else{
    //play task 3 audio file
  }
}
//function to celebrate user winning game
void congratulations(){
  //maybe audio file and haveLEDS flash or something
}

//function to display score
void displayScore(int score){
 //clear previous selections from lcd display
 lcd.clear();
 lcd.setCursor(5, 0);
 lcd.print("Score: ");
 lcd.setCursor(7,1);
 lcd.print(score);
}

//joystick movement function
bool joystickMovement(){
  //write code to see if joystick was moved
  if(analogRead(joyX)>10 || analogRead(joyY)>10 ||!digitalRead(1)){
    return true;
  }
  else{
    return false;
  }
}

//sensor check funtion
bool sensorCheck(){
  //clear trig
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  //set trig high for 10 us
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  //set duration
  duration=pulseIn(echo, HIGH);

  //calculate disatnce in cm
  distance= duration*(0.034/2);
  if(distance<=threshold){
    return true;
  }
  else{
    return false;
  }
}

void displayEndGame(){
for(int i = 0; i<5; i++){ 
 lcd.clear();
 sleep(2);
 lcd.setCursor(5, 0);
 lcd.print("Score: ");
 lcd.setCursor(7,1);
 lcd.print(score);
 sleep(2);
}
exit(1);
}
