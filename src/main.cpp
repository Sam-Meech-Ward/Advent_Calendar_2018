#include <Arduino.h>

#include "time_serial.h"
#include "date_helper.h"
#include "rom.h"
#include "CalendarMotors.h"

int daysToUnlock();
CalendarMotors motors {{7,6}, {4,3}};

void setup() {
  // Rom::reset(); return;
  pinMode(LED_BUILTIN, OUTPUT);

  TimeSerial::setup();
  TimeSerial::requestTime();

  motors.setup();
}

void loop() {
  // return;
  digitalWrite(LED_BUILTIN, HIGH);

  delay(500); 

  TimeSerial::syncTime();

  // Serial.println("Synced time");

  if (!TimeSerial::timeIsSet()) {
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    return;
  }

  delay(500);  

// Serial.println("1");
  int days = DateHelper::daysToUnlock();
  if (days > 0) {
    motors.unlockDays(days);
  }   

  // Serial.println("Rom::motorDay()");
  // Serial.println(Rom::motorDay());

  // if no days have been unlocked yet, unlock the first day as a bonus
  if (Rom::motorDay() == 0) {
    motors.unlockDays(1);
  }
  // Serial.println("3");
}