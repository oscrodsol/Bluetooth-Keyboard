
#include <BleKeyboard.h> //Include the bluetooth keyboard library

#define BUTTON_PIN 21 //Define the pin where is the button conected

BleKeyboard bleKeyboard; //Creates an instance of the class blekeyboard

int button_state = 0; //Initialice the value of the button state

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP); //Declare the functionality of the pin
  Serial.begin(115200); //Initialice the serial in the 115200 range
  Serial.println("Starting BLE work!"); //Prints in the serial monitor
  bleKeyboard.begin(); //Starts the bluetootk protocol
}


//If the esp is connected, checks if the button is pressed, if the state of the button is low, 
//the blekeyboard prints whathever we want, in this case an A, then is set a delay to prevent malfunctions in the program
void loop() {
  if (bleKeyboard.isConnected()) { 
    button_state = digitalRead(BUTTON_PIN);
    if (button_state == LOW) {
      bleKeyboard.print("A");
      delay(100);
    }
  }
}
