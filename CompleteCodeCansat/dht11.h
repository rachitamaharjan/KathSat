#include <dht11.h>
#define DHT11PIN 2

dht11 DHT11;

//void setup()
//{
//  Serial.begin(9600);
// 
//}

void dhtPrint()
{
  Serial.println();

  int chk = DHT11.read(DHT11PIN);

  Serial.print("\nHumidity (%):\t ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Temperature (C): ");
  Serial.println((float)DHT11.temperature, 2);

  delay(2000);

}
