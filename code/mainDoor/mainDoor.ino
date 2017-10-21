/****************************************************************************************************
 * Home Control Center (HCC)                                                                        *
 *                                                                                                  *
 * This code controll main door.                                                                    *
 * Send a message each time door state change.                                                      *
 * The communication channel is a Xbee module.                                                      *
 * When door is closed, the state value is 0, and when door is open, the state value is 1           *
 ****************************************************************************************************/


//PINS DEFINITION
#define doorSensor 4


//GLOBAL VARIABLES
int doorState = 0;
int doorStateOld = 0;


//SETUP
void setup() {
  //Initialization serial comunication in 9600 bauds
  Serial.begin(9600);
  //Define mode of pin doorState
  pinMode(doorState, INPUT);
}


//MAIN
void loop () {
  //Read main door state
  doorState = digitalRead(doorSensor);
  
  //If door state change, notify the new state
  if (doorState != doorStateOld) {
    if (doorState == 1) {
      Serial.println("Main door is open!");
    } else {
      Serial.println("Main door is closed!");
    }
    doorStateOld = doorState;
  }
  
  //Delay 1"
  delay(1000);
}


