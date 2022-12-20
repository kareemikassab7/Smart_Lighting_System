# Smart Lighting System

### Wiki Page
<a href="https://github.com/shalan/CSCE4301-WiKi/wiki/G6:-Smart-Lighting-System"> Check Wiki for details</a>


## How to Build it
### Circuit
-  connect 4 LEDs anodes with A0,A1,A2, and A3 and their cathodes to the GND in the arduino nano 33 BLE
-  connect the ESP32 Tx and Rx with the Rx and Tx (opposites) with the arduino nano, and the GND with GND
-  connect the RTC DS3231 with the Arduino nano: SCL to A5, SDA to A4, and VCC to 3.3v and GND to GND
-  connect the light sensor GNd to GND of arduino nano and the to A6

### Software Build
- open the arduino IDE 2.0 on your PC and connect your PC USB to the arduino via a micro usb cable
- open the .ino file
- build the project and deploy it on the arduino (make sure to have the required libraries)

### How to Use it




## 1.Overview
### Motivation
Smart home lighting systems help solve such problems and save power/electricity through automatic control, scheduled control, and monitoring consumption. Our project is a smart lighting system that satisfies the convenience need to users (its easier to power lights on and off via remote control) in addition to energy saving and consumption monitoring needs.

### Overview:
a smart lighting system will be needed in all of the future's smart homes. The system will have a set of features to maximize user control. The system should utilize multiple sensors to turn lights on and off based on people's presence in the room to save energy when people go out; Also, it should utilize a light sensor to turnoff/dim lights when there is natural light. Users should be able to set schedule to have lights automatically turned on at certain times of the day. for more convenience, users should be able to turn on/off the lights when they clap in the room (mode should be turned on and off)(luxury feature). based on power and usage time, the system will be calculating power consumption and sending this data to the user. 

## 2. Requirements and Features
### User Requirements
- users should be able to turn lights on and off without reaching out to wall switches
- users should be able to control lights through their voice
- users should be able to control lights through their phone
- users should be able to set lighting schedules from their phone
- users should be able to set autmatic lighting when it gets dark
- users should be able to monitor their consumption
 
### Proposed Features:
* Light on clap
* Light on voice command
* control intencity via voice command
* Light on motion
* Light on time
* Turnoff/Dim light on natural light
* Send power consumption statistics to cloud and in a message


## 3. Design (S/W and H/W)

### Used Hardware Components
* Light bulb / LED with range
* Light sensor
* RTC D3231 module
* Arduino Nano 33 BLE board
* ESP32 WROOM-32 board

### Hardware Design
- 4 LED's are used to simulate multiple rooms in a house. they are connected on A0 to A3
- the light sensor is connected to the arduino analog port A6 to measure light intensity and signal to LEDs/rooms that have the autmatic mood to light on and off
- the RTC D3231 module is connected to the arduino with SCL tto A5, SDA to A4, VCC to 3.3V, and GND to GND. it tracks time and we use it to compare the now time acquired by it to the user specificed schedules
- Arduino Nano33 BLE board is our main board, it integrates all the code modules and connects to the other hardware components through its analog interfaces.
- ESP 32 is used to let the user interface with whatsapp and through wifi then communicates with the arduino. it connects on the Tx and Rx ports.

### Software Design
the code is modular with a function to handle each mode with the corresponding room in each iteration.
<br>
schedule_handler is a function to handle user input schedules <br>
check_lighting is a function to compare the light sensor measurment and turn on or off based on the room's lighting<br>
there is a final function for voice control that implements the ML model to recognize commands. <br>

The main loop consists of a for loop that loops with an index i that represents a room in each iteration; in each iteration, we check an array that represents the mode of each room. taking the mode of the corresponding room, we go into a switch case statement to determine which function to execute, execute it, break, and repeat to go to the next room.

### Flow Chart
![image](https://user-images.githubusercontent.com/57846377/208563731-b9eb917e-914c-496d-b5e2-6bb05b2c212b.png)


## 5.The final project status (including demo videos)
### final design
![image](https://user-images.githubusercontent.com/57846377/208568431-2147d1ed-58c0-481e-a679-c89e8fbb0a57.png)

### Demo:

## 8. References
- https://docs.arduino.cc/resources/datasheets/ABX00031-datasheet.pdf
- https://forum.arduino.cc/t/lighting-leds-by-time-schedule/118481
- https://forum.arduino.cc/t/turn-led-on-with-rtc/620120
- https://forum.arduino.cc/t/serial-communication-between-arduino-nano-33-ble-sense-and-esp32/931623/2
- https://forum.arduino.cc/t/connecting-esp32-with-arduino-nano-33-ble-sense-usinc-i2c/886302
- https://www.programmingboss.com/2021/04/esp32-arduino-serial-communication-with-code.html
