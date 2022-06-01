#include <Arduino.h>
#include "pluie.hpp"
#include "blynk.hpp"  //code blynk 

void readpluieSensor(int sensorPin,int moteurPin){ //
  int pluieValue = analogRead(sensorPin);  // Read the analog value from sensor
    int outputValue = map(pluieValue, 0, 1023, 255, 0); // map the 10-bit data to 8-bit data
   Serial.println(outputValue);  
  
if(outputValue>=-200) 
  {
    Serial.println("-- fermer serre --"); 
    digitalWrite(moteurPin,HIGH);
    Blynk.notify("-- fermer serre --");
  }
else
  {
    Serial.println("-- ouvrir serre --");
    digitalWrite(moteurPin, LOW);
    Blynk.notify("-- ouvrir serre --");
  }
}