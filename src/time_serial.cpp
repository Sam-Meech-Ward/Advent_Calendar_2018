#include "time_serial.h"

const String timestampPrefix = "timestamp:";
const String datePrefix = "#date";

timeStatus_t TimeSerial::status() {
  return timeStatus();
}

boolean TimeSerial::timeIsSet() {
  return TimeSerial::status() != timeNotSet;
}

void TimeSerial::setup()  {
  Serial.begin(57600);
  while (!Serial);
}

void TimeSerial::requestTime() {
  Serial.println(datePrefix);
}

static time_t setTime(String time) {
  time_t timeStamp = 0;

  if (time.startsWith(timestampPrefix)) {
    timeStamp = time.substring(timestampPrefix.length()).toInt();
    setTime(timeStamp); // Sync Arduino clock to the time received on the serial port
  }

  return timeStamp;
}

void TimeSerial::syncTime() {
  if (!Serial.available()) {
    return;
  }
  if (TimeSerial::timeIsSet()) {
    return;
  }

  time_t timeStamp = setTime(Serial.readString());

  Serial.print("timestamp: ");
  Serial.println(timeStamp);
}