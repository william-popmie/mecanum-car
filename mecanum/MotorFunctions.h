#ifndef MOTORFUNCTIONS_H
#define MOTORFUNCTIONS_H

typedef struct Motor{
  int pin1;
  int pin2;
  int pinE;
} Motor;

// extern Motor m1;
// extern Motor m2;
// extern Motor m3;
// extern Motor m4;


typedef struct Car{
  Motor motor1;
  Motor motor2;
  Motor motor3;
  Motor motor4;
} Car;

// extern Car car;

void InitMotor(Motor motor);

void MotorForward(Motor motor, int speed);
void MotorBackward(Motor motor, int speed);
void MotorStop(Motor motor);

void Forward(Car car, int speed);
void Backward(Car car, int speed);
void Stop(Car car);

#endif