#include "CalendarMotors.h"

constexpr int totalDaysInRow = 11;
// We're going away for a few days in the middle of december
constexpr int totalDaysToSkipBetweenRows = 4;

void CalendarMotors::setup() {
  pinMode(bottomMotor.directionPin, OUTPUT); 
  pinMode(bottomMotor.stepPin, OUTPUT);
  pinMode(topMotor.directionPin, OUTPUT); 
  pinMode(topMotor.stepPin, OUTPUT);

  digitalWrite(bottomMotor.directionPin, LOW); 
  digitalWrite(topMotor.directionPin, LOW); 

  digitalWrite(topMotor.stepPin, LOW); 
  digitalWrite(bottomMotor.stepPin, LOW); 
}

// 200 steps is a full rotation
void CalendarMotors::moveMotor(CalendarMotor motor, int days) {
  for (int i = 0; i < days*5; i++) {
    for(int x = 0; x < 200; x++) {
      digitalWrite(motor.stepPin, HIGH); 
      delayMicroseconds(1000); 
      digitalWrite(motor.stepPin, LOW); 
      delayMicroseconds(1000); 
    }
    delay(500);
  }
}

static int maximum(int a, int b) {
  return (a > b) ? a : b;
}

void CalendarMotors::unlockDays(int days) {
  Serial.print("Current DAy");
  Serial.println(currentDay);

  int topDays = 0;
  int bottomDays = 0;
  if (currentDay <= totalDaysInRow) {
    // top
    topDays = days;
    
    int overflow = (currentDay + days) - totalDaysInRow;
    if (overflow > 0 && overflow < totalDaysToSkipBetweenRows) {
      topDays = totalDaysInRow;
    } else if (overflow > 0) {
      // both
      bottomDays = maximum(overflow-totalDaysToSkipBetweenRows, 0);
      topDays = days - bottomDays - totalDaysToSkipBetweenRows;
    }
  } else if (currentDay <= totalDaysInRow*2+totalDaysToSkipBetweenRows) {
    // bottom
    if (currentDay < totalDaysInRow+totalDaysToSkipBetweenRows) {
      bottomDays = maximum(currentDay+days-totalDaysToSkipBetweenRows-totalDaysInRow, 0);
    } else {
      bottomDays = days;
    }
  }

  Serial.print("move the top motor: ");
  Serial.println(topDays);
  Serial.print("move the bottom motor: ");
  Serial.println(bottomDays);
  moveMotor(topMotor, topDays);
  moveMotor(bottomMotor, bottomDays);

  currentDay += days;
  Rom::setMotorDay(currentDay);
}
