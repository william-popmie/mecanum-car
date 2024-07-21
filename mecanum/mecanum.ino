struct Motor{
  const int pin1;
  const int pin2;
  const int pinE;
};

struct Car{
  const Motor motor1;
  const Motor motor2;
  const Motor motor3;
  const Motor motor4;
};

Motor m1 = {2, 3, 5};
Motor m2 = {4, 6, 7};
Motor m3 = {8, 9, 10};
Motor m4 = {11, 12, 13};

Car car = {m1, m2, m3, m4};

void InitMotor(Motor motor){
  pinMode(motor.pin1, OUTPUT);
  pinMode(motor.pin2, OUTPUT);
  pinMode(motor.pinE, OUTPUT);
}

void MotorForward(Motor motor, int speed){
  digitalWrite(motor.pin1, LOW);
  digitalWrite(motor.pin2, HIGH);
  analogWrite(motor.pinE, speed);
}

void MotorBackward(Motor motor, int speed){
  digitalWrite(motor.pin1, HIGH);
  digitalWrite(motor.pin2, LOW);
  analogWrite(motor.pinE, speed);
}

void MotorStop(Motor motor){
  digitalWrite(motor.pin1, LOW);
  digitalWrite(motor.pin2, LOW);
}

void Forward(Car car, int speed){
  MotorForward(car.motor1, speed);
  MotorForward(car.motor2, speed);
  MotorForward(car.motor3, speed);
  MotorForward(car.motor4, speed);
}

void setup(){
  InitMotor(m1);
  InitMotor(m2);
  InitMotor(m3);
  InitMotor(m4);
}

void loop(){
  Forward(car, 100);
}