#include <Wire.h>
#include "RTClib.h"
#include <Time.h>
#include <TimeAlarms.h>
RTC_DS3231 rtc;
DateTime my_now;


int L0 = 13;                  // first room on A0
int L1 = 12;                // second room on A1
int L2 = 11;                 // third room on A2
int L3= 10;                 // last room on A3
char t[32];

int L0_hour;
int L0_min;
int L1_hour;
int L1_min;
int L2_hour;
int L2_min;
int L3_hour;
int L3_min;



void setup () {

    Serial.begin(9600);
    Wire.begin();
  rtc.begin();
  if (! rtc.begin()) 
  {
    Serial.println(" RTC Module not Present");
    while (1);
  }

// set time similar to computer
  rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));

// if lose power reset date time
  if (rtc.lostPower()) 
  {
    Serial.println("RTC power failure, reset the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  
  // manual set
  //year, month, date, hour, minute, and second
  //rtc.adjust(DateTime(2019, 1, 21, 5, 0, 0));
}

void  loop(){  
 Datetime my_now= rtc.now();
  sprintf(t, "%02d:%02d:%02d %02d/%02d/%02d", my_now.hour(), my_now.minute(), my_now.second(), my_now.day(), my_now.month(), my_now.year());  
  Serial.print(F("Date/Time: "));
  L0_hour= 18;
L0_min = 1;
  Schedule_Handler(A0, 18,0,18,1);
  //Serial.println(t);
  delay(1000);
}



void Schedule_Handler(int roomnumber, int startHour, int startMin, int endHour, int endMin){
  my_now = rtc.now();
    if( (my_now.hour()>startHour && my_now.hour()<endHour) || ((my_now.hour()==endHour)&&(my_now.minute()<endMin)))
  {
    analogWrite(roomnumber,HIGH);
  }
  else{
  analogWrite(roomnumber,LOW);

  }
}
