#include "Controller.h"
#include "MotorFunctions.h"

void setup(){
  Serial.begin(115200);
  InitESPNOW();
  InitMotors();
}

void loop(){
  // switch (controller.dir){
  //   case 0:
  //     Stop();
  //     break;
  //   case 3:
  //     Forward(255);
  //     break;
  //   case 7:
  //     Backward(255);
  //     break;
  // }
  Serial.println("HELLO");
}