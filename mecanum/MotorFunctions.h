#ifndef MOTORFUNCTIONS_H
#define MOTORFUNCTIONS_H

typedef struct Motor{
  int pin1;
  int pin2;
  int pinE;
} Motor;

typedef struct Car{
  Motor motor1;
  Motor motor2;
  Motor motor3;
  Motor motor4;
} Car;

void InitMotor(Motor motor);
void InitMotors();

void MotorForward(Motor motor, int speed);
void MotorBackward(Motor motor, int speed);
void MotorStop(Motor motor);

void Forward(int speed);
void Backward(int speed);
void Stop();

#endif