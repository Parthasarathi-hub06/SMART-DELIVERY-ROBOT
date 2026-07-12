/* Module Seperate Transmittion */

// I2C LCD DISPLAY is connected to SDA - SCL

// Servo Motor ServoName is connect to ServoPin
#include<SoftwareSerial.h>  // For Bluetooth Connection
#include <NewPing.h>
#include <LCD_I2C.h>
LCD_I2C lcd(0x27, 16, 2);
int Scrolling_Speed = 20;
String message = " AUTONOMOUS SMART DELIVERY ROBOT USING OTP BASED ACCESS SYSTEM ";

#include <Servo.h>
Servo ServoName;
int ServoName_pos = 0;