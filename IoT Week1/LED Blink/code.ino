// LED Blink Program - v1.3
// Description: Added blink counter and improved structure

const int LED_PIN = 13;
const int BLINK_DELAY = 1000;

int blinkCount = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("LED Blink Program v1.3 Started");
}

void loop() {
  blinkCount++;

  digitalWrite(LED_PIN, HIGH);
  Serial.print("Blink #");
  Serial.print(blinkCount);
  Serial.println(" - LED ON");
  delay(BLINK_DELAY);

  digitalWrite(LED_PIN, LOW);
  Serial.println("LED OFF");
  delay(BLINK_DELAY);
}
