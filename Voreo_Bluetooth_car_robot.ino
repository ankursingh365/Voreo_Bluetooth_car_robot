// This is the main file of the project.

#include <Servo.h>  // Library for controlling servo motor

// Servo motor setup
#define servo_pin 3  // Pin number -> 3 attached to servo motor
// Create Servo object
Servo vereoServo;  // Servo function
// Servo angles
const int straightAngle = 90;  // Center position
const int leftAngle = 180;     // Left position
const int rightAngle = 0;      // Right position

// DC motors setup
int m1 = 4, m2 = 5, m3 = 7, m4 = 6;  // Pins assigned to respective motors
int enA = 10, enB = 9;               // Enable pins for speed control for the respective DC motors

// Ultrasonic sensor setup
// Pin Definitions for Ultrasonic Sensor
#define trig_Pin 11  // Pin assigned to transmitter
#define echo_Pin 8   // Pin assigned to receiver

long duration;
float distance;
const float safeDist = 10.0;  // Minimum safe distenace in cm

// IR sensor setup
#define ir1_Pin 2     // Pin assigned to the 1st IR sensor
#define ir2_Pin 12    // Pin assigned to the 2nd IR sensor
int irThreshold = 0;  // To detect object within the range

char command;
volatile bool flag = 1;

#define ledPin A2

void setup() {
  // put your setup code here, to run once:

  // Initialize DC motor
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  // Initialize ultrasonic sensor
  pinMode(trig_Pin, OUTPUT);
  pinMode(echo_Pin, INPUT);

  // Initialize IR sensor
  pinMode(ir1_Pin, INPUT);
  pinMode(ir2_Pin, INPUT);

  // Initialize servo motor
  vereoServo.attach(servo_pin);
  vereoServo.write(straightAngle);  // Start the servo at the center position

  // Initialize LED Pin
  pinMode(ledPin, OUTPUT);  // To check if the robot is receiving command or not

  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) {
    command = Serial.read();
    Serial.println(command);     // Print received command for debugging
    digitalWrite(ledPin, HIGH);  // Turn on LED when command received
    delay(200);
    digitalWrite(ledPin, LOW);  // Turn off LED after short delay

    // Manual Mode //
    if (command == 'G' || command == 'H' || command == 'I' || command == 'J' || command == 'K'
        || command == 'A' || command == 'M' || command == 'N' || command == 'P') {
      flag = 1;
      manualControl();
    }

    // Voice Mode //
    else if (command == 'f' || command == 'b' || command == 'r' || command == 'l' || command == 's'
             || command == 'F' || command == 'B' || command == 'R' || command == 'L' || command == 'S') {
      flag = 1;
      voiceControl();
    }
  }
}

//********************************************** Manual Mode Code**************************************************************//
void manualControl() {
  if (command == 'G') {
    moveForward();
  } else if (command == 'H') {
    moveBackward();
  } else if (command == 'I') {
    moveRight();
  } else if (command == 'J') {
    moveLeft();
  } else if (command == 'K') {
    stopMotors();
  } else if (command == 'A') {
    forwardRight();
  } else if (command == 'M') {
    backwardRight();
  } else if (command == 'N') {
    forwardLeft();
  } else if (command == 'P') {
    backwardLeft();
  }
}

//**************************************************** Voice Mode Code **********************************************************//
void voiceControl() {
  if (command == 'f' || command == 'F') {
    voiceForward();
  } else if (command == 'b' || command == 'B') {
    voiceBackward();
  } else if (command == 'r' || command == 'R') {
    voiceRight();
  } else if (command == 'l' || command == 'L') {
    voiceLeft();
  } else if (command == 's' || command == 'S') {
    stopMotors();
  }
}

//*********************************************************** MODE CHANGE **************************************************//
/* Reading char 'O' on serial for stopping current mode */
void changeMode() {
  if (Serial.available() > 0) {
    command = Serial.read();

    if (command == 'O') {
      flag = 0;
      reset();
    }
  }
}

/* Stopping DC motors and bringing servo motor to original position */
void reset() {
  analogWrite(enA, 0);  // Stop motor A
  analogWrite(enB, 0);  // Stop motor B
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
  vereoServo.write(straightAngle);

  while (true) {
    loop();
  }
}