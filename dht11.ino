/**
 * DHT11 Sensor Reader
 * This sketch reads temperature and humidity data from the DHT11 sensor and prints the values to the serial port.
 * It also handles potential error states that might occur during reading.
 *
 * Author: Dhruba Saha
 * Version: 2.1.0
 * License: MIT
 */

// Include the DHT11 library for interfacing with the sensor.
#include <DHT11.h>
#include <Wire.h>
#include "rgb_lcd.h"
// Create an instance of the DHT11 class.
// - For Arduino: Connect the sensor to Digital I/O Pin 2.
// - For ESP32: Connect the sensor to pin GPIO2 or P2.
// - For ESP8266: Connect the sensor to GPIO2 or D4.

DHT11 dht11(2);
rgb_lcd lcd;

int kelvin = 273;
int temperatura_celsius = 0;
int humidity = 0;

void setup() {
    // Initialize serial communication to allow debugging and data readout.
    // Using a baud rate of 9600 bps.
    Serial.begin(9600);
    lcd.begin(16,2);
    lcd.setRGB(255,0,0);
    
    // Uncomment the line below to set a custom delay between sensor readings (in milliseconds).
    // dht11.setDelay(500); // Set this to the desired delay. Default is 500ms.
}

void loop() {
    //lcd.clear();

    // Attempt to read the temperature and humidity values from the DHT11 sensor.
    int result = dht11.readTemperatureHumidity(temperatura_celsius, humidity);

    // Check the results of the readings.
    // If the reading is successful, print the temperature and humidity values.
    // If there are errors, print the appropriate error messages.
    if (result == 0) {

        lcd.setCursor(0, 0);
        lcd.print("Temperatura: ");
        lcd.setCursor(12, 0);
        lcd.print(temperatura_celsius);
        lcd.setCursor(14, 0);
        lcd.print("C");
        lcd.setCursor(0, 1);
        lcd.print("Humidade:");
        lcd.setCursor(9,1);
        lcd.print(humidity);
        lcd.setCursor(11, 1);
        lcd.print("%");

    } 
    

    //delay(1000);
}
