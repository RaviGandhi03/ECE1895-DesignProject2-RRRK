// ECE 1895: Design Project 2 (BopIt) 
// Team Sigma (Ryan Hankee, Ravi Gandhi, Kamden Sarkey, Reece Basehore) 

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SD.h>

/* DIGITAL PIN INPUTS FOR BUTTTONS ARE PULLED HIGH SO PRESSING BUTTON MAKES INPUT GO LOW */

/*  TASK 1= BUTTON
 *  TASK 2=JOYSTICK
 *  TASK 3=ULTRASONIC SENSOR  */

//------------------------------------------------------------------------------//

/*  Variable Declaration  */ 

LiquidCrystal_I2C lcd(0x27, 16, 2);         //  declare LCD display

int buttonTask=4;         //  buttons
int startPin=0;           //  initialize startpin

int joyX=A0;              //  define joystickX
int joyY=A1;              //  define joystickY
int sw=1;                 //  pressed input

int trig=3;               //  define sensor
int echo=2;               //  ??

int threshold=20;         //  define threshold for ultrasonic sensor

long duration;            //  sensor variables      
int distance;             //  sensor variables 

int greenLED=6;           //  set greenLED pin (6)
int redLED=7;             //  set redLED pin (7)

//------------------------------------------------------------------------------//

void setup() {

/*  Initialize LCD Display  */
  lcd.init();
  lcd.backlight();

/*  Define inputs and outputs for pins  */
  pinMode(joyX, OUTPUT);
  pinMode(joyY, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
  pinMode(buttonTask, INPUT_PULLUP);
  pinMode(startPin, INPUT_PULLUP);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  randomSeed(analogRead(3)); //used to create random num
  
}

void loop() {

  //create variables to keep track of score and set equal to 0 before start of each game;
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
  previousTime=millis(); 
  //wait for response or answer
  while((millis()-previousTime)<=decisionTime+10){
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
  int num=random(1,4); //gives num random number 1-3
  return num;
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
  //a little confused what is being done here. This program will show score for about 5 microseconds due to loop and then just pause program with score displayed
for(int i = 0; i<5; i++){ 
 lcd.clear();
 lcd.setCursor(5, 0);
 lcd.print("Score: ");
 lcd.setCursor(7,1);
 //score is not declared in this scope!!!!!
 //lcd.print(score);
}
/* POSSIBLE END GAME FUNCTION PSUEDO
 *  display game over and then play sound from SD card signifying loss
 *  while(1){
 *    then display score and switch between game over and score until reset button is pressed
 *  }
 */

}
