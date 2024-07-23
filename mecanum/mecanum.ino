#include <esp_now.h>
#include <WiFi.h>

//----------------------------------------------------------------------
// CONTROLLER
//----------------------------------------------------------------------
typedef struct structController {
  bool connected;
  int dir;
} structController;

structController controller;
void OnDataRecv(const esp_now_recv_info *info, const uint8_t *incomingData, int len);

//----------------------------------------------------------------------
// MOTOR
//----------------------------------------------------------------------
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

Motor m1 = {4, 5, 18};
Motor m2 = {0, 2, 15};
Motor m3 = {33, 25, 32};
Motor m4 = {27, 26, 14};

Car car = {m1, m2, m3, m4};

void InitMotor(Motor motor);
void InitMotors();

void MotorForward(Motor motor, int speed);
void MotorBackward(Motor motor, int speed);
void MotorStop(Motor motor);

void Forward(int speed);
void Backward(int speed);
void Stop();

//----------------------------------------------------------------------
// MAIN
//----------------------------------------------------------------------
void setup(){
  Serial.begin(115200);
  Serial.println("SETUP START");
  InitESPNOW();
  Serial.println("ESP STARTED");
  InitMotors();
}

void loop(){
  Serial.println("HELLO");
  Serial.println(controller.dir);

  switch (controller.dir){
    case 0:
      Stop();
      break;
    case 1:
      Left(255);
      break;
    case 3:
      Forward(255);
      break;
    case 5:
      Right(255);
      break;
    case 7:
      Backward(255);
      break;
  }
}

//----------------------------------------------------------------------
// MOTOR
//----------------------------------------------------------------------


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

void TurnLeft(int speed) {
  MotorBackward(car.motor1, speed);
  MotorForward(car.motor2, speed);
  MotorBackward(car.motor3, speed);
  MotorForward(car.motor4, speed);
}

void TurnRight(int speed) {
  MotorForward(car.motor1, speed);
  MotorBackward(car.motor2, speed);
  MotorForward(car.motor3, speed);
  MotorBackward(car.motor4, speed);
}

void Left(int speed) {
  MotorForward(car.motor1, speed);
  MotorBackward(car.motor2, speed);
  MotorBackward(car.motor3, speed);
  MotorForward(car.motor4, speed);
}

void Right(int speed) {
  MotorBackward(car.motor1, speed);
  MotorForward(car.motor2, speed);
  MotorForward(car.motor3, speed);
  MotorBackward(car.motor4, speed);
}

void Stop() {
  MotorStop(car.motor1);
  MotorStop(car.motor2);
  MotorStop(car.motor3);
  MotorStop(car.motor4);
}

//----------------------------------------------------------------------
// CONTROLLER
//----------------------------------------------------------------------
void InitESPNOW() {
  WiFi.mode(WIFI_STA); // Set WiFi to station mode
  if (esp_now_init() != ESP_OK) { // Initialize ESP-NOW
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_register_recv_cb(OnDataRecv); // Register the receive callback
}

// Callback when data is received
void OnDataRecv(const esp_now_recv_info *info, const uint8_t *incomingData, int len) {
  memcpy(&controller, incomingData, sizeof(controller));
}