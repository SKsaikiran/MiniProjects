# SMART IRRIGATION


Here in this program we have interfaced  **Esp8266** with some sensors like Soil Moisture sensor, DHT11, Smoke sensor to develop a **Smart Irrigation** process .The above program is to perform some task like reading soil moisture value to automatically turn on a water pump , DHT11 sensor to indicate humidity and temperature of the region and Smoke sensor is to used to indicate the smoke level in the atmosphere . This are some functionality of the program for Smart irrigation. The all the data will be displayed **BLYNK Application** in real time .

## Functionally of Sensor
- **Soil moisture Sensor** - This sensor is used to read the Soil moisture of the land if the data(value) is less then certain value it initiate motor to turn ON so the required amount of water is supplied .The data will be displayed in Blynk application in real time where we can remotely monitor the status of the motor as well as the abstract values of moisture level in soil.
- **DHT11** - This sensor is used to read the Humidity and  Temperature of the region of given irrigation land .Where the value of the temperature and humidity will be showed in real time in the serial monitor of IDE and will be updated in Blynk application where values will displayed in the form of digital gauge and a graph  in real time.
- **Smoke Sensor(MQ-2)** - A Smoke sensor is a electronic fire-protection device that automatically senses the presence of smoke, as a key indication of fire . The sensor read the Smoke value of the atmosphere and if the value crosses certain value it means that a indication of fire and give a warning and set fire alarm system ON. The value of smoke sensor will be updated in Blynk application in real time in and displayed in the form of Gauge.

## Advantages

- **Save Water And Money** -Smart irrigation systems deliver exactly the amount of water that is needed. This helps keep plants and lawns healthy and beautiful.
- **Long Term Enhanced Landscape Health** - Smart irrigation controllers can be adjusted to water yards and plants the exact amount of water needed so they can thrive.
- **Can be monitor anytime** - The data will be send to the cloud in real time, so by the Blynk application one can monitor the required data at any time at any place.

## Components used 
ESP8266 , Soil moister sensor , DHT11 , Smoke sensor , Relay , 5v water pump , LED , Jump wires . 

### Pin Description
| **Sensor** | **GPIO PIN DESCRIPTION** |
|:----:|:----:|
|Soil moisture| A0|
|Smoke (MQ-2)|D7|
|DHT11|D4|
|Relay|D3|
|LED|D2|
#### Note : Connect the ground and vcc of the sensor pin to the GPIO of ESP8266 correspondingly .
