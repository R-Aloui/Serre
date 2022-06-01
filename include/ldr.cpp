#include <Arduino.h>
#include "ldr.hpp"
#include "blynk.hpp"  //code blynk 
void readldrSensor(int ldrPin,int ledldr){
  int ldrValue = analogRead(ldrPin);  // Read the analog value from sensor
 if (isnan(ldrValue)) {
    Serial.println(F("Failed to read from ldr sensor!"));
    delay(2000);
    return;
  }
if(ldrValue <= 20) 
  {
    digitalWrite(ledldr, HIGH);

Serial.print("Its DARK, Turn on LED  ");
Serial.println(ldrValue);
Blynk.notify("Its DARK, Turn on LED");
  }
else
  {
   digitalWrite(ledldr, LOW);

Serial.print("Its BRIGHT, Turn off LED  ");
Blynk.notify("Its BRIGHT, Turn off LED");
Serial.println(ldrValue);
  }
}