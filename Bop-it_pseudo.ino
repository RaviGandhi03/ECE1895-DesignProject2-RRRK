//********DIGITAL PIN INPUTS FOR BUTTTONS ARE PULLED HIGH SO PRESSING BUTTON MAKES INPUT GO LOW
void setup() {
  // put your setup code here, to run once:
  //create pin input and outputs
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //creat variables to keep track of score;
  int score=0;
  //wait to see if start button has been pressed
  while(digitalRead(StartPin)){
    //stay here until start button is pressed
  }
  //once button is pressed play game until score reaches 100 or incorrect response
  while(score<=99){
  //set digital outputs all low
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
    if(!digitalRead(taskOneInput)){
      userResponse=1;
      break;
    }
    else if(!digitalRead(taskTwoInput)){
      userResponse=2;
      break;
    }
    else if(!digitalRead(taskThreeInput)){
      userResponse=3;
      break;
    }
    //no response was picked in alloted time
    else if((millis()-previousTime)>=decisionTime){
      //notify user of incorrect response and end game
    }
  }

  //check to see if user picked correct response
  if(userResponse==correctTask){
    //notify user correct score was made
    //increment score and display score
    score++
    displayScore(score);
  }
  else{
    //notify user of incorrect response and end game
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
  
}
