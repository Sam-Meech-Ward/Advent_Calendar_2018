# Advent Calendar 2018

This is the code that runs on the Arduino UNO for my [2018 Advent Calendar Project](https://sammeechward.com) and the [Computer Serial](https://github.com/Sam-Meech-Ward/Calendar_Computer_Serial) code.

This is basically how the app works:

1. Try to get the current date and time through a serial connection. The arduino can't accurately do anything without this information, so the first thing it does is to request the current time and date. This can be handled by the computer it's plugged into, by running the [Computer Serial](https://github.com/Sam-Meech-Ward/Calendar_Computer_Serial) script.
2. If the date and time **hasn't** been synced, just blink the built in LED until it does get synced.
3. If the date and time **has** been synced, check how many days should be unlocked. This gets checked every second and will be `0` most of the time. But if it's past mid day, and the door for today hasn't been unlocked yet, this value will be `1`. Also, if the calendar hasn't been turned on for a couple of days, this value might be more.
4. Tell the motors to unlock the days.
5. Eat the candy.


## The Code

_Disclaimer: This is **not** good code. I am not a C++ developer. I don't know what C++'s plan is for dependency injection, and i'm not efficient when testing C++ code, so most of the code wasn't tested. The code works, but could be much better._

### `main`

The entry point to the application. It links up all of the other files and flashes an LED when the time is not synced.

### `time_serial`

The arduino doesn't know what the current date or time is, so every time it's powered on, we need to give it this information. The `time_serial.cpp` manages requesting the date over a serial connection, then storing it on the board to be used by other parts of the application.

### `date_helper`

The `date_helper` manages how many days of candy to unlock. Calling `DateHelper::daysToUnlock()` will return the number of days that should be unlocked right now. If the calendar was plugged in continuously, this would return `1` once per day. If you unplugged the calendar for a couple of days, this number would be higher when you plugged it back in. 

### `CalendarMotors`

Manages the motors. First, you have to set up and instance of this class with the information about each motor. Then, you can just call `CalendarMotors::unlockDays()` and pass in the number of days it needs to unlock. The `CalendarMotors` takes care of actually unlocking the doors.

### `rom`

Information like 'how many days have been unlocked' and 'when was the last day a door was unlocked' need to be persisted to the Arduino's ROM. This file manages all data persistance. 