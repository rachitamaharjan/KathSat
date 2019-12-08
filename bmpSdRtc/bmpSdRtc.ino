#include <SD.h>
#include <SPI.h>
#include <DS3231.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;

 char status;
  double T,P,p0,a;
File file;
DS3231  rtc(SDA, SCL);
int CS_pin = 10; // Pin 10 on Arduino Uno
//const int sensor_pin = A0;
//float temp;  
//float output;

void setup() {
  Serial.begin(9600);
//  pinMode(sensor_pin,INPUT);
  pinMode(CS_pin, OUTPUT);
  rtc.begin(); 
  // SD Card Initialization
  if (SD.begin())
  {
    Serial.println("SD card is ready to use.");
  } else
  {
    Serial.println("SD card initialization failed");
    return;
  }
  Serial.print("Call sign  ");   
  Serial.print("\t");
  Serial.print("Type");
  Serial.print("\t");
  Serial.print("Date  ");   
  Serial.print(" : ");
  Serial.print("Time");
  Serial.print("\t");
//  Serial.print("Temp");
//  Serial.println("\t");
  Serial.println("Altitude");

  file = SD.open("test.txt", FILE_WRITE);
  if (file) { 
    file.print("Call sign  ");   
    file.print("\t");
    file.print("Type");
    file.print("\t");
    file.print("Date");   
    file.print(" : ");
    file.print("Time");
    file.print("\t");
//    file.print("Temp");
//    file.println("\t");
    file.println("Altitude");
    file.close(); // close the file
  }
  // if the file didn't open, print an error:
  else {
    Serial.println("error opening test.txt");
  }
  if (!bmp.begin()) {
  Serial.println("Could not find a valid BMP085/BMP180 sensor, check wiring!");
  while (1) {}
  }
}

void loop() {
//  output = analogRead(sensor_pin);
//  temp =(output*500)/1023;
  Serial.print("RoboFOSS");
  Serial.print("\t");
  Serial.print("\t");
  Serial.print("Descent");
  Serial.print("\t");
  Serial.print(rtc.getDateStr());
  Serial.print(" : ");
  Serial.print(rtc.getTimeStr());
  Serial.print("\t");
  Serial.println(bmp.readAltitude());

//  Serial.println(temp);
 
  file = SD.open("test.txt", FILE_WRITE);
  if (file) {   
    file.print("RoboFOSS");
    file.print("\t");
    file.print("\t");
    file.print("Descent"); 
    file.print("\t");
    file.print(rtc.getDateStr());
    file.print(" : ");   
    file.print(rtc.getTimeStr());
    file.print("\t");
    file.print(bmp.readAltitude());
    file.print("\n");
//    Serial.println("altitude");
//    file.println(temp);
    file.close(); // close the file
  }
  // if the file didn't open, print an error:
  else {
    Serial.println("error opening test.txt");
  }
  delay(1000);
 
}
