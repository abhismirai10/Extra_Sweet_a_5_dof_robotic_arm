#include <Servo.h>

Servo yaw_servo;
Servo pitch_servo;
Servo wrist_servo;
Servo rist_servo;
Servo gripper_servo;

#define yaw_servo_pin 9
#define pitch_servo_pin 10
#define wrist_servo_pin 11
#define rist_servo_pin 12
#define gripper_servo_pin 13

void setup() {
  Serial.begin(9600);
  yaw_servo.attach(yaw_servo_pin);
  pitch_servo.attach(pitch_servo_pin);
  wrist_servo.attach(wrist_servo_pin);
  rist_servo.attach(rist_servo_pin);
  gripper_servo.attach(gripper_servo_pin);

  // Move all servos to initial position (90 degrees)
  yaw_servo.write(90);
  pitch_servo.write(90);
  wrist_servo.write(90);
  rist_servo.write(90);
  gripper_servo.write(90);

  delay(1000); // Delay for 1 second
}

void loop() {
  // Perform startup sequence
  moveServoRange(yaw_servo, 70, 110, 90);
  moveServoRange(rist_servo, 60, 60, 500);
  moveServoRange(gripper_servo, 70, 140, 50);
  moveServoRange(gripper_servo, 140, 70, 50);
  moveServoRange(rist_servo, 90, 90, 500);
  moveServoRange(gripper_servo, 70, 140, 40);
  moveServoRange(gripper_servo, 140, 70, 40);
  moveServoRange(rist_servo, 120, 120, 500);
  moveServoRange(wrist_servo, 70, 70, 500);
  moveServoRange(yaw_servo, 90, 90, 90);
  moveServoRange(gripper_servo, 70, 140, 30);
  moveServoRange(gripper_servo, 140, 70, 30);

  // End of startup sequence, loop will not execute further
  while (true) {
    // Do nothing
  }
}

void moveServoRange(Servo servo, int start, int end, int delayTime) {
  for (int pos = start; pos <= end; pos++) {
    servo.write(pos);
    delay(delayTime);
  }
}
