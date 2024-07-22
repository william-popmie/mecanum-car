#include "Controller.h"
#include "MotorFunctions.h"

void setup(){
  Serial.begin(115200);
  Serial.println("SETUP START");
  InitESPNOW();
  Serial.println("ESP STARTED");

  InitMotors();
  Serial.println("INITTED MOTORS");
}

void loop(){
  Serial.println("HELLO");
  Serial.println(controller.dir);
  switch (controller.dir){
    case 0:
      Stop();
      break;
    case 3:
      Forward(255);
      break;
    case 7:
      Backward(255);
      break;
  }
}
