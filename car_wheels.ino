// This File includes the movement of the wheels for the car robot to move.

// Function to move the robot forward
void moveForward() {
  changeMode();
  delay(100);
  if (flag == 1) {
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
    // Set the speed for the DC motors
    analogWrite(enA, 255);  // Max speed for motor A
    analogWrite(enB, 255);  // Max speed for motor B
  }
}

// Function to move the robot backward
void moveBackward() {
  changeMode();
  delay(100);
  if (flag == 1) {
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
    // Set the speed for the DC motors
    analogWrite(enA, 255);  // Max speed for motor A
    analogWrite(enB, 255);  // Max speed for motor B
  }
}

// Function to move the robot in Right direction
void moveRight() {
  changeMode();
  delay(100);
  if (flag == 1) {
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
    // Set the speed for the DC motors
    analogWrite(enA, 255);  // Max speed for motor A
    analogWrite(enB, 255);  // Max speed for motor B
  }
}

// Function to move the robot in Left direction
void moveLeft() {
  changeMode();
  delay(100);
  if (flag == 1) {
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
    // Set the speed for the DC motors
    analogWrite(enA, 255);  // Max speed for motor A
    analogWrite(enB, 255);  // Max speed for motor B
  }
}

// Function to stop the robot
void stopMotors() {
  changeMode();
  delay(100);
  if (flag == 1) {
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
    vereoServo.write(straightAngle);
  }
}

// Function to move the robot in Forward Right direction
void forwardRight() {
  changeMode();
  delay(100);
  if (flag == 1) {
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
    // Set the speed for the DC motors
    analogWrite(enA, 255);  // Max speed for motor A
    analogWrite(enB, 255);  // Max speed for motor B
  }
}

// Function to move the robot in Backward Right direction
void backwardRight() {
  changeMode();
  delay(100);
  if (flag == 1) {
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
    // Set the speed for the DC motors
    analogWrite(enA, 255);  // Max speed for motor A
    analogWrite(enB, 255);  // Max speed for motor B
  }
}

// Function to move the robot in Forward Right direction
void forwardLeft() {
  changeMode();
  delay(100);
  if (flag == 1) {
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
    // Set the speed for the DC motors
    analogWrite(enA, 255);  // Max speed for motor A
    analogWrite(enB, 255);  // Max speed for motor B
  }
}

// Function to move the robot in Backward Left direction
void backwardLeft() {
  changeMode();
  delay(100);
  if (flag == 1) {
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
    // Set the speed for the DC motors
    analogWrite(enA, 255);  // Max speed for motor A
    analogWrite(enB, 255);  // Max speed for motor B
  }
}