/*
 * Motor Cordination Test
 * 
 * Experiment with moving two motors in coordiation
 */

int enableMotor1 = 5;
int input1 = 6;
int input2 = 7;

int enableMotor2 = 3;
int input3 = 2;
int input4 = 4;

void initMotors() {
  Serial.println("Initialize and enable Motor 1 and 2");
  pinMode(enableMotor1, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);

  pinMode(enableMotor2, OUTPUT);
  pinMode(input3, OUTPUT);
  pinMode(input4, OUTPUT);
}

void initPosition() {
  Serial.println("Calibrate initial motor position");
  motor1Forward();
  motor2Forward();
  delay(4000);
  motor1Stop();
  motor2Backward();
  delay(1000);
  motor2Stop();
}

void setup() {
  Serial.begin(9600);
  Serial.println("Setup motors");
  initMotors();
  initPosition();
}

void motor1Forward() {
  Serial.println("Motor 1 forward");
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
}

void motor1Backward() {
  Serial.println("Motor 1 backward");
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);
}

void motor2Forward() {
  Serial.println("Motor 2 forward");
  digitalWrite(input3, HIGH);
  digitalWrite(input4, LOW);
}

void motor2Backward() {
  Serial.println("Motor 2 backward");
  digitalWrite(input3, LOW);
  digitalWrite(input4, HIGH);
}

void motor1Stop() {
  Serial.println("Motor 1 stop");
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
}

void motor2Stop() {
  Serial.println("Motor 2 stop");
  digitalWrite(input3, LOW);
  digitalWrite(input4, LOW);
}

void forward() {
  Serial.println("Forward");
  motor1Backward();
  motor2Forward();
  delay(1000);
  motor1Stop();
  motor2Backward();
  delay(1000);
  motor1Forward();
  motor2Stop();
  delay(2000);
  motor1Stop();
}

void backward() {
  Serial.println("Backward");
}

void loop() {
  if (Serial.available() > 0) {
    int command = Serial.read();
    if (command == '1') {
      forward();
    } else if (command == '2') {
      backward();
    } else { // Default to STOP
      motor1Stop();
      motor2Stop();
    }
  }
}
