#include <Servo.h>

Servo servos[5]; // Array to store servo objects
int servoPins[5] = {9, 10, 11, 12, 13}; // Array to store servo pins

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 5; i++) {
    servos[i].attach(servoPins[i]);
    servos[i].write(90); // Set servo to 90 degrees
  }
}

void loop() {
  // Nothing to do, all servos stay at 90 degrees
}
