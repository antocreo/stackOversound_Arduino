/*
 //================================================================================================================================================//
 //==================================================== S T A C K   O V E R S O U N D ============================================================//
 //===============================================================================================================================================//
 
 //Author: Antonio Daniele
 //PROTOTYPE FOR A MEMORY PUZZLE FOR KIDS
 //PROJECT 01 FOR CRUFT FEST 2016
 //ECS742 Interactive Digital Media Techniques - PhD MAT Programme QMUL
 
 //STACK OVERSOUND
 //is a prototype for an interactive memory puzzle for kids.
 //It can be used with songs, sounds, separate tracks, storytelling and everything that can be splitted and shuffled.
 
 //================================================================================================================================================//
 //================================================================================================================================================//
 //================================================================================================================================================//
 
 
 */

#define BUTTONS_SIZE  6                  //constant num of buttons (rings)

//Variables:

int startState = 0;                       //the seq Button is initially at LOW
int lastStartState = 0;                   //the seq Button is initially at LOW
int startBtn = 9;                         //the start button PIN
int lastButton = 10;                      //just a flag for the buttons of the seq to be pressed or not  IS NOT A PIN           

//create an array of booleans to store the status of each button
boolean buttonState[BUTTONS_SIZE] = {
  0,0,0,0,0,0};

//creating an array of 8 buttons (the indeces refer to the digital pins)
int buttons[BUTTONS_SIZE]  = { 
  2,3,4,5,6,7};


void setup(){

  //loop to set all the buttons as INPUT
  for(int i=0; i<BUTTONS_SIZE; i++){
    pinMode(buttons[i], INPUT);
  }
  pinMode (startBtn, INPUT);  // setting start as INPUT

    //Begin serial communication
  Serial.begin(115200);       

}

void loop(){

  startState = digitalRead(startBtn);     //initial state of the button
  //if button is pressed //this is used for the start button //to implement
  if(startState == HIGH){
    Serial.println('r');
  } 
  //if the start button is off do this
  else if (startState == LOW){

    for(int i=0; i<BUTTONS_SIZE; i++){

      //what's the state of the button?
      buttonState[i] = digitalRead(buttons[i]);
      //send me a string with the buttons state
      Serial.print(buttonState[i]);

      //divide each status with a comma but the last one
      if(i<BUTTONS_SIZE-1){
        Serial.print(",");
      }
    }
    //break line
    Serial.println();
  }
}


























































































































