#include <Servo.h>

Servo servos[5]; // Array to store servo objects
int potPins[4] = {A0, A1, A2, A3}; // Array to store potentiometer pins
int servoPins[5] = {9, 10, 11, 12, 13}; // Array to store servo pins
int servoMin[5] = {0, 40, 20, 0, 10}; // Array to store minimum servo positions
int servoMax[5] = {180, 140, 160, 180, 170}; // Array to store maximum servo positions
int potMin[4] = {127, 127, 127, 127}; // Array to store minimum potentiometer inputs
int potMax[4] = {895, 895, 895, 895}; // Array to store maximum potentiometer inputs
#define DEADBAND 2

void setup() {
  Serial.begin(9600);
  
  for (int i = 0; i < 5; i++) {
    if (i < 4) {
      pinMode(potPins[i], INPUT);
    } else {
      pinMode(potPins[i], INPUT_PULLUP); // Using internal pull-up resistor for the button
    }
    servos[i].attach(servoPins[i]);
    servos[i].write(90); // Initialize servo to 90 degrees
  }
}

void loop() {
  for (int i = 0; i < 5; i++) {
    int potValue;
    if (i < 4) {
      potValue = analogRead(potPins[i]);
    } else {
      // Read push button state: if 1, set servo position to 150; if 0, set servo position to 30
      potValue = digitalRead(potPins[i]) ? 150 : 30;
    }

    // Ensure potValue stays within the expected range
    if (i < 4) {
      if (potValue < potMin[i]) {
        potValue = potMin[i];
      } else if (potValue > potMax[i]) {
        potValue = potMax[i];
      }
    }

    int servoPosition;
    if (i < 4) {
      servoPosition = map(potValue, potMin[i], potMax[i], servoMin[i], servoMax[i]);
    } else {
      servoPosition = potValue;
    }
    
    if (abs(servoPosition - servos[i].read()) > DEADBAND) {
      servos[i].write(servoPosition);
    }
    
    Serial.print("Servo ");
    Serial.print(i + 1);
    Serial.print(" Position: ");
    Serial.print(servoPosition);
    Serial.print("  ");
  }
  Serial.println("");
}
