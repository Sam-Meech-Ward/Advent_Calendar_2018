#include "date_helper.h"

boolean isDecember2018() {
  if (year() != 2018) {
    return false;
  }

  if (month() != 12) {
    return false;
  }

  return true;
}

int DateHelper::daysSinceDecemberDay(int d) {
  if (!isDecember2018()) {
    return -1;
  }

  return day() - d; 
}