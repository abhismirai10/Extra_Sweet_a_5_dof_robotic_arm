void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT_PULLUP); // Using internal pull-up resistor for the button
}

void loop() {
  int potValues[4];
  int buttonState;

  // Read potentiometer values
  for (int i = 0; i < 4; i++) {
    potValues[i] = analogRead(A0 + i);
  }

  // Read button state
  buttonState = digitalRead(A4);

  // Print potentiometer values
  for (int i = 0; i < 4; i++) {
    Serial.print("Potentiometer ");
    Serial.print(i + 1);
    Serial.print(" Value: ");
    Serial.print(potValues[i]);
    Serial.print("  ");
  }

  // Print button state
  Serial.print("Button State: ");
  Serial.println(buttonState);

  delay(500); // Add a delay to slow down the serial output
}
