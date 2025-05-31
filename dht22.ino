
//Libraries
#include <DHT.h>
#include <Wire.h>
#include "rgb_lcd.h"

//Constants
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

rgb_lcd lcd;


float humidade;  
float temperatura_celsius;

void setup(){
    Serial.begin(9600);
	  dht.begin();
    lcd.begin(16,2);
    lcd.setRGB(255,0,0);

    pinMode(4, OUTPUT);
    pinMode(4, LOW);

    pinMode(6, OUTPUT);
    pinMode(6, LOW);

    pinMode(7, OUTPUT);
    pinMode(7, LOW);
}

void loop() {

  //lcd.clear();
  //Read data and store it to variables hum and temp

  humidade = dht.readHumidity();
  temperatura_celsius = dht.readTemperature();

  // Apaga todos os LEDs antes de decidir qual acender
  digitalWrite(4, LOW); // verde
  digitalWrite(6, LOW); // vermelho
  digitalWrite(7, LOW); // amarelo

  if (humidade <= 49.99) {
    digitalWrite(4, HIGH); // verde  
  }
  else if (humidade >= 50 && humidade <= 60.99) {
    digitalWrite(6, HIGH); // vermelho
  }
  else if (humidade >= 61){
    digitalWrite(7, HIGH); // amarelo
  }

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.setCursor(6, 0);
  lcd.print(temperatura_celsius);
  lcd.setCursor(11, 0);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Humidade:");
  lcd.setCursor(10,1);
  lcd.print(humidade);
  lcd.setCursor(15, 1);
  lcd.print("%");      
  
  delay(1000);
}


   