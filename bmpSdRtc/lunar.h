//#include <SD.h>
//#include <SPI.h>

//#include <DS3231.h>

//#include <Wire.h>
//#include <Adafruit_BMP085.h>
//
//Adafruit_BMP085 bmp;
//
//File file;
//
//DS3231  rtc(SDA, SCL);
//int CS_pin = 10; 
#include <dht11.h>
#define DHT11PIN 2
dht11 DHT11;

void lunar_setup() {
  Serial.begin(9600);
//  pinMode(sensor_pin,INPUT);
  pinMode(CS_pin, OUTPUT);
  rtc.begin(); 
//  rtc.setDate(8,12,2019);
//  rtc.setTime(16,56,0);
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
  Serial.println("Temperature");
  Serial.print("\t");
  Serial.print("Pressure");
  Serial.print("\t");
  Serial.print("Humidity");
  
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
    file.println("Temperature");
    file.print("\t");
    file.print("Pressure");
    file.print("\t");
    file.print("Humidity");
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

void lunar_loop() {
//  output = analogRead(sensor_pin);
//  temp =(output*500)/1023;
  Serial.print("\nRoboFOSS");
  Serial.print("\t");
  Serial.print("\t");
  Serial.print("Lunar");
  Serial.print("\t");
  Serial.print(rtc.getDateStr());
  Serial.print(" : ");
  Serial.print(rtc.getTimeStr());
  Serial.print("\t");
  
  int chk = DHT11.read(DHT11PIN);
  Serial.print((float)DHT11.temperature, 2);
  Serial.print("\t");
  Serial.print(bmp.readSealevelPressure());
  Serial.print("\t");
  Serial.println((float)DHT11.humidity, 2);
  Serial.print("\n");

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
    file.print((float)DHT11.temperature, 2);
    file.print("\t");
    file.print(bmp.readSealevelPressure());
    file.print("\t");
    file.println((float)DHT11.humidity, 2);
    file.print("\n");
    
    delay(500);
//    file.print("\n");
//    Serial.println("altitude");
//    file.println(temp);
    file.close(); // close the file
  }
  // if the file didn't open, print an error:
  else {
    Serial.println("error opening test.txt");
  }
  delay(500);
  
}
