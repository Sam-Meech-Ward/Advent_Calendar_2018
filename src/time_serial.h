#ifndef __time_serial_h__
#define __time_serial_h__

#include <TimeLib.h>
#include <Arduino.h>

namespace TimeSerial {
  void setup();
  // Send a time request message to computer
  void requestTime();
  // Get the time from the computer and sync it with the arduino
  void syncTime();
  boolean timeIsSet();
  timeStatus_t status();
}

#endif