#include "accelerometer.h"
#include "bmp180.h"
#include "dht11.h"
#include "rtc.h"

void setup() {
 Serial.begin(9600);
 bmp_setup();
 rtc_setup();

}

void loop() {
  accelerometerPrint();
  bmpPrint();
  dhtPrint();
  timestamp_RTC();
}
