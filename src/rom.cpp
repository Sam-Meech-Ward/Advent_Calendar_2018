#include "rom.h"

#include <EEPROM.h>


constexpr int dayAddr = 0;
constexpr int monthAddr = 1;
constexpr int motorAddr = 2;

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

int Rom::motorDay() {
  return EEPROM.read(motorAddr);
}
void Rom::setMotorDay(int d) {
  EEPROM.write(motorAddr, d);
}

void Rom::reset(){
  EEPROM.write(dayAddr, 0);
  EEPROM.write(monthAddr, 0);
  EEPROM.write(motorAddr, 0);
}