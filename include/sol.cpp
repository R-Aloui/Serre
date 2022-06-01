#include <Arduino.h>
#include "sol.hpp"

#include "blynk.hpp"  //code blynk 

void setuphumsol(int solPin,int redLED){

int solsensorValue = analogRead(solPin);
float solval= (100-((solsensorValue/4096.00)*100));

   if (isnan(solsensorValue)) {
    Serial.println(F("Failed to read from Soil Humidity sensor!"));
    delay(2000);
    return;
  }
Serial.print("Soil Humidity Value = ");
  Serial.print(solval);
  Serial.println(" % ");  
if(solval > 60){
    Serial.println("-- votre usine n'a pas besoin d'eau--");
   boolean msg=("-- votre usine n'a pas besoin d'eau--");
    digitalWrite(redLED, LOW);
blynk(solval,msg);
  }
  else {
    
Serial.println("-- votre usine besoin d'eau --");
    boolean msg=("-- votre usine besoin d'eau --");
    digitalWrite(redLED, HIGH);
    blynk(solval,msg);
    }
}