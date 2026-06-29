/*
Q15: Digital Piano using Buzzer
 
 */

const int BTN1 = 2;  // Do
const int BTN2 = 3;  // Re
const int BTN3 = 4;  // Mi
const int BTN4 = 5;  // Fa
const int BTN_MODE = 6;  // Mode toggle
const int BUZZER = 9;

// Major scale frequencies
const int majorFreqs[4] = {262, 294, 330, 349};

// Minor scale frequencies
const int minorFreqs[4] = {262, 277, 311, 349};

bool isMajor = true;
bool lastModeState = LOW;

void setup() {
  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
  pinMode(BTN3, INPUT);
  pinMode(BTN4, INPUT);
  pinMode(BTN_MODE, INPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  bool b1 = digitalRead(BTN1);
  bool b2 = digitalRead(BTN2);
  bool b3 = digitalRead(BTN3);
  bool b4 = digitalRead(BTN4);
  bool bMode = digitalRead(BTN_MODE);

  // Mode toggle - only triggers once per press
  if (bMode == HIGH && lastModeState == LOW) {
    isMajor = !isMajor;
    delay(200);  // debounce
  }
  lastModeState = bMode;

  // Pick frequency array based on current mode
  const int* freqs = isMajor ? majorFreqs : minorFreqs;

  int pressedCount = b1 + b2 + b3 + b4;

  if (pressedCount >= 2) {
    tone(BUZZER, 392);  // Sol -
