// servo control using a serial communication
// for eg Y120P120W90R90G70
// must have new line at the end

#include <Servo.h>

Servo yaw_servo;
Servo pitch_servo;
Servo wrist_servo;
Servo rist_servo;
Servo gripp_servo;

//xy_servo is yaw and xz_servo is pitch 
//same for potentiometer
#define j1_servo 9
#define j2_servo 10
#define j3_servo 11
#define j4_servo 12
#define j5_servo 13

void setup() {
  Serial.begin(9600);
  yaw_servo.attach(j1_servo);
  pitch_servo.attach(j2_servo);
  wrist_servo.attach(j3_servo);
  rist_servo.attach(j4_servo);
  gripp_servo.attach(j5_servo);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n'); // Read the full command

    int yPos = command.indexOf('Y');
    int pPos = command.indexOf('P');
    int wPos = command.indexOf('W');
    int rPos = command.indexOf('R');
    int gPos = command.indexOf('G');

    if (yPos != -1 && pPos != -1 && wPos != -1 && rPos != -1 && gPos != -1) {
      // Extract yaw position, knowing 'P' follows 'Y'
      int yawPosition = command.substring(yPos + 1, pPos).toInt();
      // Extract pitch position, knowing 'W' follows 'P'
      int pitchPosition = command.substring(pPos + 1, wPos).toInt();
      int wristPosition = command.substring(wPos + 1, rPos).toInt();
      int ristPosition = command.substring(rPos + 1, gPos).toInt();
      int grippPosition = command.substring(gPos + 1).toInt();

      // Set servo positions if within valid range
      if (yawPosition >= 60 && yawPosition <= 120) 
      {
        yaw_servo.write(yawPosition);
      }
      if (pitchPosition >= 60 && pitchPosition <= 120) 
      {
        pitch_servo.write(pitchPosition);
      }
      if (wristPosition >= 60 && wristPosition <= 120) 
      {
        wrist_servo.write(wristPosition);
      }
      if (ristPosition >= 60 && ristPosition <= 120) 
      {
        rist_servo.write(ristPosition);
      }
      if (grippPosition >= 60 && grippPosition <= 145) 
      {
        gripp_servo.write(grippPosition);
      }

      delay(500);
    }
  }
}