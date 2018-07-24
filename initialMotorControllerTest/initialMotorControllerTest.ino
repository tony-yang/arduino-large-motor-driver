// Under no load, upload this to an Arduino board attached with a new motor controller
// Test output voltage with Multimeter to measure the voltage level
// Ensure new motor board is running good

int enableMotor1 = 5;
int input1 = 6;
int input2 = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(enableMotor1, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Enabling Motor 1");
  digitalWrite(enableMotor1, HIGH);

  Serial.println("Forward motion");
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
  delay(3000);

  Serial.println("Backward motion");
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);
  delay(3000);

  Serial.println("Disabling Motor 1");
  digitalWrite(enableMotor1, LOW);
  delay(20000);
}
