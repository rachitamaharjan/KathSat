#include <SD.h>
#include <SPI.h>

#include <DS3231.h>

#include <Wire.h>
#include <Adafruit_BMP085.h>
#include "descent.h"
#include "lunar.h"

// Adafruit_BMP085 bmp;
//File file;
//DS3231  rtc(SDA, SCL);
//int CS_pin = 10; 

void setup() {
  descent_setup();
  lunar_setup();
}

void loop() {

 descent_loop();
 lunar_loop();

}
