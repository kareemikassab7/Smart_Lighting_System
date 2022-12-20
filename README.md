# Smart Lighting System

### Outline
- (1) Background and Motivation
- (2) Requirements/Features
- (3) Design (S/W and H/W)
- (4) Iterations done
- (5) The final project status including demo videos
- (6) Limitations and Future work
- (7) Conclusions
- (8) References

### Authors
**Kareem Kassab  900182771** <br>
**Elsayed Zaki  900181637** <br>
**Mohamed Roshdy  900183935**<br>
**Abdelharman Fawzy  900183004**<br>

## 1. Background and Motivation

### Problem to Solve(need):
We live in a time where energy is needed for almost everything in the current lifestyle; however, such energy is not free; thus, it must be used wisely and saved whenever possible. Furthermore, there is a convenience need that is fulfilled in smart housing systems, lighting included. a smart lighting system is needed to provide more convenience to users to turn lights on and off

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

## 4.Iterations done
## Phase1 Update:
![Demo1](https://i.ibb.co/x7qKy2d/Whats-App-Image-2022-11-30-at-2-25-44-AM.jpg)
# Demo 1:
https://drive.google.com/drive/u/0/folders/1edW1XKyQb-ulQsgd0SlEA5-SkaUFtDj7

### Design Update:
 two major modifications were done in this phase

1- we decided to implement a smarter machine learning model to enable more features of turning lights on/off and brighter/dimmer instead of a simple DSP clap because it can cause lights to go on and off on any high intensity sound.

2- we discarded the infrared sensor and followingly the turn lights on/off based on people entering the room because the smarter model
### Done so far:
- light on/off based on natural light
- light on/off on clap (higher intensity sound)
- machine learning model to light on, off, intensity up, intensity down, and frequency lighting.


![image](https://user-images.githubusercontent.com/57846377/204669973-d09e84c4-8e4b-47cf-a774-81e68088406b.png)

### Challenges faced:
- could not find a way yet to integrate the machine learning model on the circuit with its own mic (in an actual system, its not practical at all to need a laptop with its mic to run the model, it needs to be deployed to the actual embedded system).
- data received from the light sensor is not very accurate and thus affects the target intensity.

### ToDo in Phase 2:
- integrating the ESP32
- measuring consumption/analytics and sending them
-  scheduling lights on/off with timers
- deploying model on-chip + using mic on chip

### Phase 2 Update:

### Design Update:
One major design choice was made for the project as we decided to use Arduino Nano 33 BLE board as the main board in our design as it is more suitable to host the machine learning model for our project on chip. 
The board contains an on-board microphone which makes it a perfect choice for our project as it allows us to take the input (the user's voice) run the model on it and take decisions based on it. the final design now utilizes ESP32 to receive commands and communicates with aruino to manipulate lighting control modes in different rooms.

### Challenges Faced in phase2:
- software design to switch modes
- Integrating all components together


### Overview of the implemented features in the project:
* A smart house lighting system that allows the user to control the LEDs in the system through voice commands (on, off, up, down). 
* A smart machine learning model that converts the user's voice to instructions that control the state of the lights in the system.
* A report of power consumption and other power-related statistics is sent to the user periodically in order to enable him to monitor the power usage in the system and give the user more insights on how much power the system consumes.
* A scheduling system that allows the user to make the LEDs in the system turn on at certain periods throughout the day.
*The system can adjust to the lights in the surrounding environment, meaning that it can detect if there is too much light around and turn off the LEDs in order to save power, it can also detect if it is dark around and turn on the LEDs accordingly.

## 5.The final project status (including demo videos)
### final design
![image](https://user-images.githubusercontent.com/57846377/208568431-2147d1ed-58c0-481e-a679-c89e8fbb0a57.png)


### How the System looks in real life:
### System Flow:
### Demo videos of the system:
## 6. Limitations and Future work
### Limitations
- system currently doesnt support adding more rooms dynamically
- system is currently being controlled via whatsapp doesnt have attractive GUI
### Future Work
- system can be updated to be more extensible
- system can be further improved with a GUI
- Cost can be minimized if one board has the model and wifi
## 7. Conclusions

## 8. References
- https://docs.arduino.cc/resources/datasheets/ABX00031-datasheet.pdf
- https://forum.arduino.cc/t/lighting-leds-by-time-schedule/118481
- https://forum.arduino.cc/t/turn-led-on-with-rtc/620120
- https://forum.arduino.cc/t/serial-communication-between-arduino-nano-33-ble-sense-and-esp32/931623/2
- https://forum.arduino.cc/t/connecting-esp32-with-arduino-nano-33-ble-sense-usinc-i2c/886302
- https://www.programmingboss.com/2021/04/esp32-arduino-serial-communication-with-code.html
