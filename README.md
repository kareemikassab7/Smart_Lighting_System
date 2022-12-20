# G6: Smart Lighting System

### authors
**Kareem Kassab  900182771** <br>
**Elsayed Zaki  900181637** <br>
**Mohamed Roshdy  900183935**<br>
**Abdelharman Fawzy  900183004**<br>

### github repo:

## Proposed Idea:

### Problem to Solve(need):
We live in a time where energy is needed for almost everything in the current lifestyle; however, such energy is not free; thus, it must be used wisely and saved whenever possible. Smart home lighting systems help solve such problems and save power/electricity through automatic control, scheduled control, and monitoring consumption. Our project is a smart lighting system that satisfies the convenience need to users (its easier to power lights on and off via remote control) in addition to energy saving and consumption monitoring needs.

### Overview:
a smart lighting system will be needed in all of the future's smart homes. The system will have a set of features to maximize user control. The system should utilize multiple sensors to turn lights on and off based on people's presence in the room to save energy when people go out; Also, it should utilize a light sensor to turnoff/dim lights when there is natural light. Users should be able to set schedule to have lights automatically turned on at certain times of the day. for more convenience, users should be able to turn on/off the lights when they clap in the room (mode should be turned on and off)(luxury feature). based on power and usage time, the system will be calculating power consumption and sending this data to the user. 


### Proposed Features:
* Light on clap
* Light on motion
* Light on time
* Turnoff/Dim light on natural light
* Send power consumption statistics to cloud and in a message


### Proposed Hardware Components
* Light bulb / LED with range
* Dimmer 
* //LED capacitive touch dimmer PWM control board 
* Light sensor
* Infrared sensor
* Sound sensor
* RTC module
* STM32 board
* ESP32 board

### Software:
- STM32CubeMX
- Keil µVision

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
One major design choice was made for the project as we decided to use Arduino Nano 33 BLE board as the main board in our design as it is more suitable to host the machine learning model for our project. 
The board contains an on-board microphone which makes it a perfect choice for our project as it allows us to take the input (the user's voice) run the model on it and take decisions based on it. The board also supports WIFI which eliminates the need to use the ESP32 board in order to communicate with the user through Whatsapp or any other platform.

### Challenges Faced:


### Overview of the implemented features in the project:
* A smart house lighting system that allows the user to control the LEDs in the system through voice commands (on, off, up, down). 
* A smart machine learning model that converts the user's voice to instructions that control the state of the lights in the system.
* A report of power consumption and other power-related statistics is sent to the user periodically in order to enable him to monitor the power usage in the system and give the user more insights on how much power the system consumes.
* A scheduling system that allows the user to make the LEDs in the system turn on at certain periods throughout the day.
*The system can adjust to the lights in the surrounding environment, meaning that it can detect if there is too much light around and turn off the LEDs in order to save power, it can also detect if it is dark around and turn on the LEDs accordingly.

### Update system design

![SystemDesign](https://user-images.githubusercontent.com/92397424/208532200-da3be9a4-3b6c-44bd-9372-304cb05cf2b7.PNG)
)

### How the System looks in real life:

### How the system works:

### demo videos of the system:
