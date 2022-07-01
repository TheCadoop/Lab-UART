/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/cademissner/Desktop/IoT/Lab-UART/src/Lab-UART.ino"
void setup();
void loop();
#line 1 "/Users/cademissner/Desktop/IoT/Lab-UART/src/Lab-UART.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

#define LED_PIN D2
#define BUTTON_PIN D3
char buttonOn;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(LED_PIN , OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}


void loop() {
  if (Serial1.available() > 0) {
    char value = Serial1.read();
    Serial.println(value);

    if (value == '1') {
      digitalWrite(LED_PIN, HIGH);
    } else if (value == '0') {
      digitalWrite(LED_PIN, LOW);
    } else if (value == '?') {
      if (digitalRead(BUTTON_PIN) == LOW) {
        buttonOn = '1';
      } else {
        buttonOn = '0';
      }
      Serial1.print(buttonOn);
    }
  }
}