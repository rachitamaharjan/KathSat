//#include <SD.h>
//#include <SPI.h>
//
//#include <DS3231.h>
//
//#include <Wire.h>
//#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;

File file;
double alt;
//double 

DS3231  rtc(SDA, SCL);
int CS_pin = 10; 

void descent_setup() {
  Serial.begin(9600);
//  pinMode(sensor_pin,INPUT);
  pinMode(CS_pin, OUTPUT);
  rtc.begin(); 
//  alt = bmp.readAltitude();
//  rtc.setTime(15,40,0);
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
  Serial.print("\t");
  Serial.print("AccelerationX");
  Serial.print("\t");
  Serial.print("AccelerationY");
  Serial.print("\t");
  Serial.print("AccelerationZ");
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
    file.print("\t");
    file.print("AccelerationX");
    file.print("\t");
    file.print("AccelerationY");
    file.print("\t");
    file.print("AccelerationZ\n");
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

void descent_loop() {
//  output = analogRead(sensor_pin);
//  temp =(output*500)/1023;
  Serial.print("\nRoboFOSS");
  Serial.print("\t");
  Serial.print("\t");
  Serial.print("Descent");
  Serial.print("\t");
  Serial.print(rtc.getDateStr());
  Serial.print(" : ");
  Serial.print(rtc.getTimeStr());
  Serial.print("\t");
  alt = bmp.readAltitude(102000); //current sea level pressure in Nepal
//  alt = bmp.readAltitude();

  Serial.println(alt);

//  Serial.println(temp);
  int x = analogRead(1);  //read from xpin
 
   int y = analogRead(2);  //read from ypin
   
   int z = analogRead(3);  //read from zpin
   
    float zero_G = 512.0; //ADC is 0~1023  the zero g output equal to Vs/2
                          //ADXL335 power supply by Vs 3.3V
    float scale = 102.3;  //ADXL335330 Sensitivity is 330mv/g
                           //330 * 1024/3.3/1000 
    
    //Serial.print(x);
    //Serial.print("\t");
    //Serial.print(y);
    //Serial.print("\t");
    //Serial.print(z); 
    Serial.print("\t");
    Serial.print(((float)x - 331.5)/65*9.8);  //print x value on serial monitor
    Serial.print("\t");
    Serial.print(((float)y - 329.5)/68.5*9.8);  //print y value on serial monitor
    Serial.print("\t");
    Serial.print(((float)z - 340)/68*9.8);  //print z value on serial monitor
    Serial.print("\n\n");
    delay(500);
 
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
    file.print(alt);
    file.print("\t");
    file.print(((float)x - 331.5)/65*9.8);  //print x value on serial monitor
    file.print("\t");
    file.print(((float)y - 329.5)/68.5*9.8);  //print y value on serial monitor
    file.print("\t");
    file.print(((float)z - 340)/68*9.8);  //print z value on serial monitor
    file.print("\n\n");
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
