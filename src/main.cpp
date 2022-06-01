#include <Arduino.h>
#include "DHT.h"

#include "blynk.hpp"  //code blynk
#include "sol.hpp"      //capteur humidté de sol
#include "pluie.hpp"  //capteur de pluie
#include "ldr.hpp"  //capteur de lumiere 

#define DHT11PIN 4
const int LEDPIN = 21; 
DHT dht(4, DHT11);

int redLED=25;          //sol led
int solPin=34;            //sol Pin

int moteurPin=26;      //pluie led
#define sensorPin 4            //pluie Pin

int ledldr = 13;      //ldr led
int ldrPin = 35;      //ldr Pin

void setup()
{
  Serial.begin(9600);
/* Start the DHT11 Sensor */
pinMode(LEDPIN, OUTPUT);
  dht.begin();

/* Start the soil moister Sensor */
   pinMode(solPin, INPUT);
  pinMode(redLED, OUTPUT);

/* Start rain Sensor */
    pinMode(sensorPin, INPUT);
  pinMode(moteurPin, OUTPUT);

/* Start ldr Sensor */
  pinMode(ldrPin, INPUT);
  pinMode(ledldr, OUTPUT);
  
}

void loop()
{
  Blynk.run();
  float humi = dht.readHumidity();
  float temp = dht.readTemperature();

  if (isnan(humi) || isnan(temp)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    delay(2000);
    return;
  }

  if ( (humi>80) || (temp>37) ) 
{ 
  Serial.println("ouvrir ventilateur ");
boolean msg=("ouvrir ventilateur");
blynk(temp,humi,msg);
digitalWrite(LEDPIN, HIGH); 
  delay(2000);
}
else 
{
  Serial.println("ventilateur fermer ");
digitalWrite(LEDPIN, LOW); 
boolean msg=("ouvrir ventilateur");
blynk(temp,humi,msg);
 delay(2000);
}

setuphumsol(solPin,redLED);
  delay(1000);

readpluieSensor(sensorPin,moteurPin);
  delay(1000);

readldrSensor(ldrPin,ledldr);
  delay(1000);
}