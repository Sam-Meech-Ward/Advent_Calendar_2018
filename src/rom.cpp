#include "rom.h"

#include <EEPROM.h>


constexpr int dayAddr = 0;
constexpr int monthAddr = 0;

void Rom::updateDate() {
  EEPROM.write(dayAddr, day());
  EEPROM.write(monthAddr, month());
}

int Rom::getDay() {
  return EEPROM.read(dayAddr);
}
int Rom::getMonth() {
  return EEPROM.read(monthAddr);
}