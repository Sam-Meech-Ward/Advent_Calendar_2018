#include <Arduino.h>

#include "time_serial.h"
#include "date_helper.h"
#include "rom.h"

int daysToUnlock();

void setup() {
  TimeSerial::setup();
  TimeSerial::requestTime();

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  

  digitalWrite(LED_BUILTIN, HIGH);

  delay(500); 

  TimeSerial::syncTime();

  if (!TimeSerial::timeIsSet()) {
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    return;
  }

  delay(500);  

  int days = daysToUnlock();  
}

int daysToUnlock() {
  int day = Rom::getDay();
  int month = Rom::getMonth();
  int days = DateHelper::daysSinceDecemberDay(day, month);
  if (days > 0) {
    Rom::updateDate();
  }
  return days;
}