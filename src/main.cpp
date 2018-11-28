#include <Arduino.h>

#include "time_serial.h"

void setup() {
  TimeSerial::setup();
  TimeSerial::requestTime();

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);

  TimeSerial::syncTime();

  delay(500);

  if (TimeSerial::timeIsSet()) {
    Serial.println(year());
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

   delay(500);  
}