#include <Servo.h>

Servo myServo; // Create a servo object
int potPin = A5; // Define potentiometer pin
int servoPin = 13; // Define servo pin

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin); // Attach the servo to its pin
}

void loop() {
  int potValue = analogRead(potPin); // Read potentiometer value
  int servoPosition = map(potValue, 0, 1023, 0, 180); // Map potentiometer value to servo range
  myServo.write(servoPosition); // Set servo position based on potentiometer value
  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);
  Serial.print(", Servo Position: ");
  Serial.println(servoPosition);
  delay(15); // Add a small delay to smooth out servo movement
}
