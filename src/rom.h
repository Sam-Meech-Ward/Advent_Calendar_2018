#ifndef __rom_h__
#define __rom_h__

#include <TimeLib.h>

namespace Rom {
  void updateDate();
  int getDay();
  int getMonth();
  
  // motor state
  int motorDay();
  void setMotorDay(int day);

  void reset();
};

#endif