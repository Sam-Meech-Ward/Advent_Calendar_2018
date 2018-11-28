#include <EEPROM.h>

static int addr = 0;

void updateDay(int day) {
  EEPROM.write(addr, day);
}

int getDay() {
  return EEPROM.read(addr);
}