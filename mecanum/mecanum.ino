#include "Controller.h"
#include "MotorFunctions.h"

void setup(){
  Serial.begin(115200);
  InitESPNOW();
}

void loop(){
  Serial.println(controller.dir);
}