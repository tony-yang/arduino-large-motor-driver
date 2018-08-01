/*
 * New motor controller and motor tester
 *
 * 1. Under no load, upload this to an Arduino board attached with a new motor controller
 * 2. Test output voltage with Multimeter to measure the voltage level
 *    Ensure new motor board is running good
 * 3. Attach a new motor to one of the motor output and run the test again
 */

int enableMotor1 = 6;
int input1 = 5;
int input2 = 7;

void setup() {
  Serial.begin(9600);
  pinMode(enableMotor1, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
}

void loop() {
  Serial.println("Enabling Motor 1");
  digitalWrite(enableMotor1, HIGH);

  Serial.println("Forward motion");
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
  delay(3000);

  Serial.println("Stop");
  digitalWrite(input1, LOW);
  digitalWrite(input1, LOW);
  delay(1000);

  Serial.println("Backward motion");
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);
  delay(3000);

  Serial.println("Disabling Motor 1");
  digitalWrite(enableMotor1, LOW);
  delay(10000);

  Serial.println("Break before PWM testing");

  Serial.println("Forward motion using PWM");
  analogWrite(enableMotor1, 64);
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
  delay(3000);

  Serial.println("Stop");
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
  delay(1000);

  Serial.println("Backward motion using PWM");
  analogWrite(enableMotor1, 64);
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);
  delay(3000);

  Serial.println("Test Complete");
  digitalWrite(enableMotor1, LOW);
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
  delay(20000);
}
