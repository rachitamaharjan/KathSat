#include "bmp.h"
#include "sdCard.h"

void setup() {
 Serial.begin(9600);
 bmp_setup();
// sd_setup();
initializeSD();
  createFile("test.txt");

}

void loop() {
  bmpPrint();
  writeToFile(T);
  if(writeToFile(T)==1){Serial.println("Done");}
//  closeFile();

}
