#ifndef __Calendar_Motors_h__
#define __Calendar_Motors_h__

#include <Arduino.h>

#include "rom.h"

struct CalendarMotor {
  CalendarMotor(int direction, int step): directionPin(direction), stepPin(step) {}
  int directionPin;
  int stepPin;
};

class CalendarMotors {
  public:
  CalendarMotors(CalendarMotor top, CalendarMotor bottom): topMotor(top), bottomMotor(bottom) {
    currentDay = Rom::motorDay();
  }
  void setup();
  void unlockDays(int days);
 
  private:
  void moveMotor(CalendarMotor motor, int steps);
  CalendarMotor topMotor;
  CalendarMotor bottomMotor;
  int currentDay;
};

#endif