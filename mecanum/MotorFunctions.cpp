#include "MotorFunctions.h"
#include <Arduino.h>

Motor m1 = {1, 22, 23};
Motor m2 = {3, 21, 19};
Motor m3 = {17, 5, 18};
Motor m4 = {16, 14, 0};

Car car = {m1, m2, m3, m4};

void InitMotor(Motor motor) {
  pinMode(motor.pin1, OUTPUT);
  pinMode(motor.pin2, OUTPUT);
  pinMode(motor.pinE, OUTPUT);
}

void InitMotors(){
  InitMotor(m1);
  InitMotor(m2);
  InitMotor(m3);
  InitMotor(m4);
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

void Forward(int speed) {
  MotorForward(car.motor1, speed);
  MotorForward(car.motor2, speed);
  MotorForward(car.motor3, speed);
  MotorForward(car.motor4, speed);
}

void Backward(int speed) {
  MotorBackward(car.motor1, speed);
  MotorBackward(car.motor2, speed);
  MotorBackward(car.motor3, speed);
  MotorBackward(car.motor4, speed);
}

void Right(int speed) {
  MotorBackward(car.motor1, speed);
  MotorForward(car.motor2, speed);
  MotorBackward(car.motor3, speed);
  MotorForward(car.motor4, speed);
}

void Left(int speed) {
  MotorForward(car.motor1, speed);
  MotorBackward(car.motor2, speed);
  MotorForward(car.motor3, speed);
  MotorBackward(car.motor4, speed);
}

void StrafeRight(int speed) {
  MotorForward(car.motor1, speed);
  MotorForward(car.motor2, speed);
  MotorBackward(car.motor3, speed);
  MotorBackward(car.motor4, speed);
}

void StrafeLeft(int speed) {
  MotorBackward(car.motor1, speed);
  MotorBackward(car.motor2, speed);
  MotorForward(car.motor3, speed);
  MotorForward(car.motor4, speed);
}

void Stop() {
  MotorStop(car.motor1);
  MotorStop(car.motor2);
  MotorStop(car.motor3);
  MotorStop(car.motor4);
}
