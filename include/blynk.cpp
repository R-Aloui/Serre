#include <Arduino.h>
#include "blynk.hpp"

#define BLYNK_TEMPLATE_ID "TMPLv74UaZh9"
#define BLYNK_DEVICE_NAME "Myserre"
#define BLYNK_PRINT Serial   
#include <SPI.h>
 #include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <WiFiClient.h>
#include <Wire.h>

char auth[] ="_gSbYMByVp52DbGJZSC85n-1ne24hq1M";               //Authentication code sent by Blynk
char ssid[] = "WLAN-ETUD";                       //WiFi SSID
char pass[] = "isetetud2122"; 

  

void blynk(float temp,float humi,boolean msg){
    Blynk.begin(auth,ssid,pass);
    Blynk.run();
   Blynk.virtualWrite(V0,temp);
 Blynk.virtualWrite(V1,humi);
 //Blynk.notify(msg);
}
void blynk(float solval,boolean msg){
    Blynk.begin(auth,ssid,pass);
    Blynk.run();
   Blynk.virtualWrite(V4,solval);
 //Blynk.notify(msg);
}