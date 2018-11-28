#ifndef __date_helper_h__
#define __date_helper_h__

#include <TimeLib.h>
#include <Arduino.h>

namespace DateHelper {
  // return the number of days since this day of december
  // so if it's december 20 and `day` is 15, 5 will get returned.
  int daysSinceDecemberDay(int day);
};

#endif