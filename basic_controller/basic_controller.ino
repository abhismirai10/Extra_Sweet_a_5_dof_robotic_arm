#include <Servo.h>

Servo servos[5]; // Array to store servo objects
int potPins[5] = {A0, A1, A2, A3, A4}; // Array to store potentiometer pins
int servoPins[5] = {9, 10, 11, 12, 13}; // Array to store servo pins
int servoMin[5] = {0, 40, 20, 0, 10}; // Array to store minimum servo positions
int servoMax[5] = {180, 140, 160, 180, 170}; // Array to store maximum servo positions
int potMin[5] = {127, 127, 127, 127, 127}; // Array to store minimum potentiometer inputs
int potMax[5] = {895, 895, 895, 895, 895}; // Array to store maximum potentiometer inputs
#define DEADBAND 2

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 5; i++) {
    pinMode(potPins[i], INPUT);
    servos[i].attach(servoPins[i]);
    servos[i].write(90); // Initialize servo to 90 degrees
  }
}

void loop() {
  for (int i = 0; i < 5; i++) {
    int potValue = analogRead(potPins[i]);

    // Ensure potValue stays within the expected range
    if (potValue < potMin[i]) {
      potValue = potMin[i];
    } else if (potValue > potMax[i]) {
      potValue = potMax[i];
    }

    int servoPosition = map(potValue, potMin[i], potMax[i], servoMin[i], servoMax[i]);
    if (abs(servoPosition - servos[i].read()) > DEADBAND) {
      servos[i].write(servoPosition);
      Serial.print("Servo ");
      Serial.print(i + 1);
      Serial.print(" Position: ");
      Serial.println(servoPosition);
    }
  }
}
