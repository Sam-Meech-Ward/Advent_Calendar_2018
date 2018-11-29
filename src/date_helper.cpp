#include "date_helper.h"
#include "rom.h"

boolean isDecember2018() {
  if (year() != 2018) {
    return false;
  }

  if (month() != 11) {
    return false;
  }

  return true;
}

boolean isPastMidDay() {
  if (hour() < 12) {
    return false;
  }

  return true;
}

int DateHelper::daysToUnlock() {
  if (!isDecember2018()) {
    return -1;
  }

  // Only unlock a day after mid day
  if (!isPastMidDay()) {
    return 0;
  }

  int currentDay = day();
  int currentMonth = month();

  int savedDay = Rom::getDay();
  int savedMonth = Rom::getMonth();

  Rom::updateDate();

  if (savedMonth < currentMonth) {
    return currentDay;
  }

  return currentDay - savedDay;
}