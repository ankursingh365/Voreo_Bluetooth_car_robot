# VOREO - Voice and Remote Bluetooth Control Car

![Voreo Car](Bluetooth%20Control%20App/Media/Final%20car.jpg)

## Overview
VOREO is a smart car project that combines voice control, remote control, and obstacle avoidance features. The car can be controlled using voice commands or a remote control via the VOREO app, which is connected through Bluetooth. The app is built using MIT App Inventor. Additionally, the car is equipped with an ultrasonic sensor for front, left, and right direction obstacle detection, and an IR sensor for detecting obstacles in the back direction.

## Features
- **Voice Control**: Control the car using voice commands via the VOREO app.
- **Remote Control**: Control the car using a remote interface on the VOREO app.
- **Obstacle Avoidance**: 
  - **Front, Left, and Right Directions**: Ultrasonic sensors detect obstacles and help the car avoid collisions.
  - **Back Direction**: IR sensor detects obstacles when the car is moving backward.
- **Bluetooth Connectivity**: Seamless connection between the car and the VOREO app via Bluetooth.

## Components
- **Microcontroller**: Arduino or any compatible microcontroller.
- **Bluetooth Module**: HC-05 for Bluetooth communication.
- **Ultrasonic Sensors**: For front, left, and right obstacle detection.
- **IR Sensor**: For back direction obstacle detection.
- **Motor Driver**: L298N or any compatible motor driver.
- **Chassis**: Car chassis with wheels and motors.
- **Power Supply**: Battery pack or any suitable power source.
- **VOREO App**: Built using MIT App Inventor for voice and remote control.

## Installation and Setup
1. **Hardware Setup**:
   - Assemble the car chassis and attach the motors.
   - Connect the motor driver to the microcontroller.
   - Attach the ultrasonic sensors to the front, left, and right sides of the car.
   - Attach the IR sensor to the back of the car.
   - Connect the Bluetooth module to the microcontroller.
   - Connect the power supply to the microcontroller and motor driver.

2. **Software Setup**:
   - Upload the provided Arduino code to the microcontroller.
   - Install the VOREO app on your smartphone.
   - Pair the smartphone with the Bluetooth module.

3. **Usage**:
   - Open the VOREO app on your smartphone.
   - Connect to the car via Bluetooth.
   - Use the voice control or remote control interface to control the car.
   - The car will automatically avoid obstacles using the ultrasonic and IR sensors.

## Code
The Arduino code for the VOREO car is available in the directory. The code includes:
- Bluetooth communication handling.
- Motor control for movement.
- Ultrasonic sensor data processing for obstacle detection.
- IR sensor data processing for back direction obstacle detection.

## VOREO App
The VOREO app is built using MIT App Inventor. The app provides:
- Voice control interface.
- Remote control interface with buttons for forward, backward, left, and right movements.
- Bluetooth connection management.

[Click here to watch the demo](Project%20Demonstration.mp4)


## Contributing
Contributions are welcome! Please fork the repository and submit a pull request with your changes.

## Acknowledgments
- MIT App Inventor for providing an easy-to-use platform for app development.
- Arduino community for extensive documentation and support.

## Contact
For any questions or suggestions, please contact Ankur Singh at [singhankur3072002@gmail.com].
