/*SMART IRRIGATION
//*************************************************************
Template ID, Device Name and Auth Token are provided by the Blynk.Cloud*/
#define BLYNK_TEMPLATE_ID "TMPLizwS4P-e"
#define BLYNK_DEVICE_NAME "Irrigation"
#define BLYNK_AUTH_TOKEN "qQwotE7hsMvBilVCOYaKR6OEuQLtVJ0X"
#define DHTPIN D4
#define DHTTYPE DHT11
#define BLYNK_PRINT Serial
#define BLYNK_PRINT Serial
#define Motor D2
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = BLYNK_AUTH_TOKEN;
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "wifi";
char pass[] = "00000000";
BlynkTimer timer;
DHT_Unified dht(DHTPIN, DHTTYPE);
// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}
void moisture() {
  int value = analogRead(A0);
  value = map(value, 0, 1023, 0, 100);
  Serial.println(value);
}
void myTimerEvent()
{
  
  //Write Code Here:
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  Serial.print("Temperature: ");
  float temp = float(event.temperature);
  Serial.print(event.temperature);
  Blynk.virtualWrite(V1, temp);
  Serial.println("°C");
    
  dht.humidity().getEvent(&event);
  Serial.print("Relative Humidity: ");
  float hum = float(event.relative_humidity);
  Serial.print(hum);
  Blynk.virtualWrite(V2, hum);
  Serial.println("%");
  Serial.println("\n-------------------------------");
 
}
  void setup() 
  {
  pinMode(Motor,OUTPUT);
  dht.begin();
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);
  }
void loop()
{
   float moisture_percentage;
  moisture_percentage =  ( 100.00 - ( (analogRead(A0)/1024.00)*100));
  Serial.print("Soil Moisture(in Percentage) = ");
  Serial.print(moisture_percentage);
  Serial.println("%");
  if(moisture_percentage<=30)
  {
    Serial.println("ON");
    digitalWrite(Motor,HIGH);
  }
 else
{
  Serial.println("OFF");
  digitalWrite(Motor,LOW);
}
  Blynk.virtualWrite(V0,moisture_percentage);
  myTimerEvent();
  delay(1000);  
  Blynk.run();
  timer.run();  
}
