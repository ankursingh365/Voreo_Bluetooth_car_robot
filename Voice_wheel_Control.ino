// This file includes the movement of the robot car according to voice command

/* When voice input is "Forward" */
void voiceForward() {
  vereoServo.write(straightAngle);  // Servo centered
  delay(100);
  getDistance();

  while (true) {
    if (distance > safeDist) {
      Serial.println("No obstacle detected.");
      moveForward();
      getDistance();  // Continuously check the distance
    }

    else if (distance < safeDist) {
      goto stop;
    }
  }
stop:
  Serial.println("Obstacle detected.");
  stopMotors();
  Serial.print("Distance: ");
  Serial.println(distance);
}

/* When voice input is "Backward" */
void voiceBackward() {
  moveBackward();
  while (true) {
    // Check for obstacles with IR sensors in backward direction
    int ir1 = digitalRead(ir1_Pin);  // Read the value from IR sensor 1
    int ir2 = digitalRead(ir2_Pin);  // Read the value from IR sensor 2
    Serial.print("IR1: ");
    Serial.print(ir1);
    Serial.print(" IR2: ");
    Serial.println(ir2);

    if (ir1 == irThreshold || ir2 == irThreshold) {  // Obstacle detected
      Serial.println("Obstacle detected");
      stopMotors();  // Stop the motors
      break;         // Exit the loop to handle the obstacle
    }
    moveBackward();  // Continue moving backward
    delay(100);      // Delay to prevent rapid sensor polling
  }
}

// /* When voice input is "Left" */
// void voiceLeft() {
//   vereoServo.write(leftAngle);  // Rotate servo to the left
//   delay(200);
//   getDistance();
//   delay(300);
//   vereoServo.write(straightAngle);  // Center the servo after delay
//   delay(200);

//   Serial.print("Distance: ");
//   Serial.println(distance);

//   if (distance > safeDist) {
//     Serial.print("No obstacle detected.");
//     moveLeft();
//     delay(1000);
//   }

//   while (true) {
//     if (distance > safeDist) {
//       moveForward();
//       getDistance();
//     } else if (distance < safeDist) {
//       goto stop;
//     }
//   }
// stop:
//   Serial.println("Obstacle detected.");
//   stopMotors();
// }

// /* When voice input is "Right" */
// void voiceRight() {
//   vereoServo.write(rightAngle);  // Rotate servo to the right
//   delay(200);
//   getDistance();
//   delay(300);
//   vereoServo.write(straightAngle);  // Center the servo after delay
//   delay(200);

//   Serial.print("Distance: ");
//   Serial.println(distance);

//   if (distance > safeDist) {
//     Serial.print("No obstacle detected.");
//     moveRight();
//     delay(1000);
//   }

//   while (true) {
//     if (distance > safeDist) {
//       moveForward();
//       getDistance();
//     } else if (distance < safeDist) {
//       goto stop;
//     }
//   }
// stop:
//   Serial.println("Obstacle detected.");
//   stopMotors();
// }

/* When voice input is "Left" */
void voiceLeft() {
  moveLeft();
  delay(500);
  vereoServo.write(straightAngle);  // Servo centered
  delay(100);
  getDistance();

  while (true) {
    if (distance > safeDist) {
      Serial.println("No obstacle detected.");
      moveForward();
      getDistance();  // Continuously check the distance
    }

    else if (distance < safeDist) {
      goto stop;
    }
  }
stop:
  Serial.println("Obstacle detected.");
  stopMotors();
  Serial.print("Distance: ");
  Serial.println(distance);
}

/* When voice input is "Right" */
void voiceRight() {
  moveRight();
  delay(500);
  vereoServo.write(straightAngle);  // Servo centered
  delay(100);
  getDistance();

  while (true) {
    if (distance > safeDist) {
      Serial.println("No obstacle detected.");
      moveForward();
      getDistance();  // Continuously check the distance
    }

    else if (distance < safeDist) {
      goto stop;
    }
  }
stop:
  Serial.println("Obstacle detected.");
  stopMotors();
  Serial.print("Distance: ");
  Serial.println(distance);
}