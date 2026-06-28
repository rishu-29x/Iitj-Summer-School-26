/*
 * Project: LED Blink with Potentiometer Speed Control
 * Author: Rishu Jaiswal
 * Date: 29-06-2026
 * Description: LED blinks at variable speed controlled
 *              by potentiometer. Blink count printed
 *              to Serial Monitor.
 */

int blinkCount = 0;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(A0);
  int blinkSpeed = map(potValue, 0, 1023, 100, 1000);

  blinkCount++;
  digitalWrite(13, HIGH);
  delay(blinkSpeed);
  digitalWrite(13, LOW);
  delay(blinkSpeed);

  Serial.print("Blink count: ");
  Serial.print(blinkCount);
  Serial.print(" | Speed: ");
  Serial.println(blinkSpeed);
}
