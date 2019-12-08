  
#include "bmp.h"
#include "sdCard.h"

void setup() {
 Serial.begin(115200);
 bmp_setup();
// sd_setup();
initializeSD();
  createFile("test.txt");
//    openFile("test.txt");


}

void loop() {
  bmpPrint();
  writeToFile(T,a);
  if(writeToFile(T,a)==1){Serial.println("Done");}
//  closeFile();

}
