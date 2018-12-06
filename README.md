# Advent Calendar 2018

This is the code that runs on the Arduino UNO for my [2018 Advent Calendar Project](https://www.sammeechward.com/youtube-projects/advent-calendar-2018) and the [Computer Serial](https://github.com/Sam-Meech-Ward/Calendar_Computer_Serial) code.

This is basically how the app works:

1. Try to get the current date and time through a serial connection. The arduino can't accurately do anything without this information, so the first thing it does is to request the current time and date. This can be handled by the computer it's plugged into, by running the [Computer Serial](* https://github.com/Sam-Meech-Ward/Calendar_Computer_Serial) script.
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


## Open Browser Tabs

These are all of the open browser tabs I had open by the end of writing this code:

* https://app.asana.com/0/322442483856462/923583663590757
* https://www.instructables.com/id/Program-Arduino-Pro-Mini-Using-Arduino-Uno/
* http://playground.arduino.cc/Code/dateTime
* https://www.arduino.cc/reference/en/language/functions/communication/serial/
* https://learn.sparkfun.com/tutorials/serial-communication
* https://learn.sparkfun.com/tutorials/logic-levels
* https://learn.sparkfun.com/tutorials/serial-peripheral-interface-spi
* https://learn.sparkfun.com/tutorials/i2c
* https://cdn.sparkfun.com/assets/9/6/5/5/b/51eec92ece395ffc4b000000.png
* https://www.hackster.io/harshmangukiya/serial-communication-between-two-arduino-boards-d423e9
* https://www.instructables.com/id/I2C-between-Arduinos/
* http://www.home-automation-community.com/arduino-low-power-how-to-run-atmega328p-for-a-year-on-coin-cell-battery/
* https://www.arduino.cc/reference/en/language/functions/communication/serial/println/
* https://www.google.ca/search?q=arduino+serial&oq=arduino+serial&aqs=chrome.0.69i59l2j69i60l3j0.1680j0j7&sourceid=chrome&ie=UTF-8
* https://www.arduino.cc/en/Tutorial/SoftwareSerialExample
* https://github.com/node-serialport/node-serialport#readme
* https://serialport.io/docs/en/guide-about
* https://serialport.io/docs/en/api-stream#serialport-flush
* https://www.ebay.ca/myb/Summary?MyEbay&gbh=1#PurchaseHistoryOrdersContainer?ipp=25&Period=2&Filter=1&radioChk=1&GotoPage=2&_trksid=p2060353.m2749.l4670&cmid=2749&melid=page&_trksid=p2060353.m2749.l4670
* https://www.ebay.ca/itm/FT232RL-FT232-USB-to-Serial-adapter-module-USB-TO-232-For-Arduino-pro-mini-new/322049720658?ssPageName=STRK%3AMEBIDX%3AIT&_trksid=p2060353.m2749.l2649
* https://www.google.ca/search?q=asci+letters&oq=asci+letters&aqs=chrome..69i57j69i60l5.1557j0j7&sourceid=chrome&ie=UTF-8
* http://www.asciitable.com/
* https://www.google.ca/search?q=js+date+timestamp&oq=js+date+timestamp&aqs=chrome..69i57j0l5.5471j0j7&sourceid=chrome&ie=UTF-8
* https://www.google.ca/search?q=arduino+date&oq=arduino+date&aqs=chrome..69i57j0j69i60j0l3.2717j0j7&sourceid=chrome&ie=UTF-8
* http://forum.arduino.cc/index.php?topic=388743.0
* http://playground.arduino.cc/Code/Time
* https://www.google.ca/search?q=unix+epoch+1467551156&oq=unix+epoch+1467551156&aqs=chrome..69i57j0j69i60j0l3.3306j0j7&sourceid=chrome&ie=UTF-8
* https://www.epochconverter.com/
* https://www.google.ca/search?q=arduino+turn+on+led&oq=arduino+turn+on+&aqs=chrome.0.0j69i57j0l4.2671j0j7&sourceid=chrome&ie=UTF-8
* http://www.circuitbasics.com/arduino-basics-controlling-led/
* https://www.google.ca/search?q=aruduino+string+to+int&oq=aruduino+string+to+int&aqs=chrome..69i57j0l5.6892j0j7&sourceid=chrome&ie=UTF-8
* https://www.arduino.cc/en/Tutorial.StringToIntExample
* https://www.wolframalpha.com/input/?i=log+base+2+of+1543361338378&t=crmtb01
* https://www.google.ca/search?newwindow=1&ei=2NX9W6LLOIzb_wTVzoPoAQ&q=arduino+64+bit+int&oq=arduino+64+bit&gs_l=psy-ab.3.1.0l3j0i22i30l7.21553.23085..24958...0.0..0.111.508.5j1......0....1..gws-wiz.......0i71.U4NOzgJPNNU
* https://forum.arduino.cc/index.php?topic=58697.0
* https://www.google.ca/search?newwindow=1&ei=Kdb9W9_gOZK88AOpipTYAQ&q=unix+epoch+time&oq=unix+epoch+time&gs_l=psy-ab.3..0l10.113951.120334..120485...24.0..0.112.2100.19j4......0....1..gws-wiz.......0i71j0i131j0i67j0i131i67j0i22i30j33i160j0i13.k6ruC84lSz0
* https://www.epochconverter.com/
chrome://newtab/
* https://www.google.ca/search?q=arduino+string&oq=arduino+string&aqs=chrome.0.0l2j69i60l3j0.4020j0j7&sourceid=chrome&ie=UTF-8
* https://www.arduino.cc/reference/en/language/variables/data-types/string/functions/substring/
* https://www.google.ca/search?q=install+specific+version+of+npm+module&oq=install+specific+version+of+npm+module&aqs=chrome..69i57j0l5.4532j0j7&sourceid=chrome&ie=UTF-8
* https://verdaccio.org/
* https://www.google.ca/search?q=a4988+stepper+motor+driver&oq=A4988+Stepper+Motor+Driver&aqs=chrome.0.0j69i60j0l4.275j0j7&sourceid=chrome&ie=UTF-8
* https://howtomechatronics.com/tutorials/arduino/how-to-control-stepper-motor-with-a4988-driver-and-arduino/
* https://www.google.ca/search?q=arduino+time+library&oq=arduino+time+library&aqs=chrome..69i57j0l5.4557j0j7&sourceid=chrome&ie=UTF-8
* https://www.pjrc.com/teensy/td_libs_Time.html
* https://www.google.ca/search?q=arduino+serial&oq=arduino+serial&aqs=chrome..69i57j69i60j69i59j69i60l2j0.2095j0j7&sourceid=chrome&ie=UTF-8
* https://www.arduino.cc/reference/en/language/functions/communication/serial/
* https://serialport.io/docs/en/guide-usage
* https://serialport.io/docs/en/api-stream
* https://www.google.ca/search?q=javascript+date+as+unix+epoch+timestamp&oq=javascript+date+as+unix+epoch+timestamp&aqs=chrome..69i57.8407j0j7&sourceid=chrome&ie=UTF-8
* https://coderwall.com/p/rbfl6g/how-to-get-the-correct-unix-timestamp-from-any-date-in-javascript
* https://www.google.ca/search?q=arduino+string&oq=arduino+string&aqs=chrome..69i57j69i60l3j0l2.1936j0j7&sourceid=chrome&ie=UTF-8
* https://www.arduino.cc/reference/en/language/variables/data-types/string/functions/startswith/
* https://www.google.ca/search?q=current+unix+epoch+time&oq=current+unix+epoch+time&aqs=chrome..69i57j0l4.3064j1j7&sourceid=chrome&ie=UTF-8
* https://www.epochconverter.com/
* https://www.google.ca/search?q=aruduino+flash+led&oq=aruduino+flash+led&aqs=chrome..69i57j0l5.3632j0j7&sourceid=chrome&ie=UTF-8
* https://www.arduino.cc/en/Tutorial/Blink
* https://www.google.ca/search?q=blink+arduino+pro+mini+led&oq=blink+arduino+pro+mini+led&aqs=chrome..69i57j0.6782j0j7&sourceid=chrome&ie=UTF-8
* https://www.google.ca/search?q=connect+two+arduinos+serial&oq=connect+two+arduinos+serial&aqs=chrome..69i57j0l3.3898j0j7&sourceid=chrome&ie=UTF-8
* https://www.hackster.io/harshmangukiya/serial-communication-between-two-arduino-boards-d423e9
* https://www.google.ca/search?q=arduino+pro+mini&oq=arduino+pro+mini&aqs=chrome..69i57j69i60l3j0l2.3640j0j7&sourceid=chrome&ie=UTF-8
* https://store.arduino.cc/usa/arduino-pro-mini
* https://www.google.ca/search?q=software+serial&oq=software+serial&aqs=chrome.0.0l6.2096j0j7&sourceid=chrome&ie=UTF-8
* https://www.arduino.cc/en/Reference/SoftwareSerialListen
* https://www.arduino.cc/en/Tutorial/SoftwareSerialExample
* https://www.arduino.cc/en/Tutorial/TwoPortReceive
* https://www.google.ca/search?q=software+serial+arduino+pro+mini&oq=software+serial+pro+mini+&aqs=chrome.1.69i57j0.9591j0j7&sourceid=chrome&ie=UTF-8
* https://forum.arduino.cc/index.php?topic=129881.0
* https://www.google.ca/search?newwindow=1&ei=mBn_W7rrMYO_0PEPneW6qAE&q=software+serial+arduino+pro+mini+to+uno&oq=software+serial+arduino+pro+mini+to+uno&gs_l=psy-ab.3...7945.8191..8282...0.0..0.113.208.1j1......0....1..gws-wiz.......0i71.NMII9BhWygk
* https://forum.arduino.cc/index.php?topic=418688.0
* https://www.google.ca/search?newwindow=1&q=arduino+persistent+data&sa=X&ved=0ahUKEwi9j4i1nPjeAhWWGzQIHRjpAUMQ7xYIKSgA&biw=1120&bih=566&dpr=3
* https://www.arduino.cc/en/Tutorial/EEPROMWrite
* http://forum.arduino.cc/index.php?topic=4340.0
* https://www.google.ca/search?newwindow=1&ei=Xlr_W97eNKa40PEP3sy74AM&q=c%2B%2B+constructor+initialization&oq=cpp+constructor+ini&gs_l=psy-ab.1.0.0i10l10.108.426..1318...0.0..0.327.785.1j1j1j1......0....1..gws-wiz.......0j0i71.YWhA-5duVQQ
* https://en.cppreference.com/w/cpp/language/initializer_list
* https://www.google.ca/search?q=unix+epoch+time&oq=unix+epoch&aqs=chrome.0.69i59l3j69i60j69i57j0.2664j0j7&sourceid=chrome&ie=UTF-8
* https://www.epochconverter.com/
