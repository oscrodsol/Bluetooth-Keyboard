
#include <BleKeyboard.h>

#define BUTTON_PIN 21

BleKeyboard bleKeyboard;

int button_state = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}

void loop() {
  if (bleKeyboard.isConnected()) {
    button_state = digitalRead(BUTTON_PIN);
    if (button_state == LOW) {
      bleKeyboard.print("A");
      delay(10);
    }
  }
}
