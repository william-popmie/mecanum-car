#include "MotorFunctions.h"
#include <Arduino.h>

Motor m1 = {23, 22, 21};
Motor m2 = {19, 18, 5};
Motor m3 = {17, 16, 4};
Motor m4 = {0, 2, 15};

Car car = {m1, m2, m3, m4};

void InitMotor(Motor motor) {
  pinMode(motor.pin1, OUTPUT);
  pinMode(motor.pin2, OUTPUT);
  pinMode(motor.pinE, OUTPUT);
}

void MotorForward(Motor motor, int speed) {
  digitalWrite(motor.pin1, LOW);
  digitalWrite(motor.pin2, HIGH);
  analogWrite(motor.pinE, speed);
}

void MotorBackward(Motor motor, int speed) {
  digitalWrite(motor.pin1, HIGH);
  digitalWrite(motor.pin2, LOW);
  analogWrite(motor.pinE, speed);
}

void MotorStop(Motor motor) {
  digitalWrite(motor.pin1, LOW);
  digitalWrite(motor.pin2, LOW);
}

void Forward(Car car, int speed) {
  MotorForward(car.motor1, speed);
  MotorForward(car.motor2, speed);
  MotorForward(car.motor3, speed);
  MotorForward(car.motor4, speed);
}

void Backward(Car car, int speed) {
  MotorBackward(car.motor1, speed);
  MotorBackward(car.motor2, speed);
  MotorBackward(car.motor3, speed);
  MotorBackward(car.motor4, speed);
}

void Stop(Car car) {
  MotorStop(car.motor1);
  MotorStop(car.motor2);
  MotorStop(car.motor3);
  MotorStop(car.motor4);
}
