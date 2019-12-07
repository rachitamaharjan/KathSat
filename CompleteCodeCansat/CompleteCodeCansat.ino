#include "accelerometer.h"
#include "bmp180.h"

void setup() {
 Serial.begin(9600);
 bmp_setup();

}

void loop() {
  accelerometerPrint();
  bmpPrint();
}
