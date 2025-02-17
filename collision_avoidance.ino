// This file includes collision aviodance feature in the car robot.

// --------------------------------------------- Ultrasonic sensor----------------------------------------------------- //
// using Ultrasonic sensor for Collison avoidance for (FRONT,RIGHT,LEFT) direction.
// Function to get the distance from the ultrasonic sensor
void getDistance() {
  // Send a 10us pulse to trigger pin
  digitalWrite(trig_Pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_Pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_Pin, LOW);

  // Read the echo pin and calculate distance
  duration = pulseIn(echo_Pin, HIGH);
  distance = (duration * 0.0343) / 2;  // Speed of sound is ~0.034 cm/us
  // return distance;
}