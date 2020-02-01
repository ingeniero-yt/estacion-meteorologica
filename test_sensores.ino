/*
 *      -----TEST SENSORES DHT11/22 Y BMP180-----
 * 
 * Por "Ingeniero en Casa"
 * https://www.youtube.com/channel/UCurfoG9YbFyQmxCLlxZVArg
 * 
 * La distribución y/o modificación del código es totalmente libre.
 */


#include "DHT.h"
#include "Adafruit_BMP085.h"


#define pin1 13
#define pin2 32

DHT dht1(pin1, DHT11);    //El azul.
DHT dht2(pin2, DHT22);    //El blanco.

Adafruit_BMP085 bmp;

void setup() {
  Serial.begin(115200);
  Serial.println("Test de sensores:");

  dht1.begin();
  dht2.begin();

  bmp.begin();
}

void loop() {

  delay(2000);
  leerdht1();

  delay(2000);
  leerdht2();

  delay(2000);
  leerbmp();
}

void leerdht1() {
  
  float t1 = dht1.readTemperature();
  float h1 = dht1.readHumidity();

  while (isnan(t1) || isnan(h1)){
    Serial.println("Lectura fallida en el sensor DHT11, repitiendo lectura...");
    delay(2000);
    t1 = dht1.readTemperature();
    h1 = dht1.readHumidity();
  }

  Serial.print("Temperatura DHT11: ");
  Serial.print(t1);
  Serial.println(" ºC.");

  Serial.print("Humedad DHT11: ");
  Serial.print(h1);
  Serial.println(" %."); 

  Serial.println("-----------------------");
}

void leerdht2() {
  
  float t2 = dht2.readTemperature();
  float h2 = dht2.readHumidity();

  while (isnan(t2) || isnan(h2)){
    Serial.println("Lectura fallida en el sensor DHT22, repitiendo lectura...");
    delay(2000);
    t2 = dht2.readTemperature();
    h2 = dht2.readHumidity();
  }

  Serial.print("Temperatura DHT22: ");
  Serial.print(t2);
  Serial.println(" ºC.");

  Serial.print("Humedad DHT22: ");
  Serial.print(h2);
  Serial.println(" %."); 

  Serial.println("-----------------------");
}

void leerbmp() {

  float temp = bmp.readTemperature();
  float presion = bmp.readPressure();
  float altitud = bmp.readAltitude();

  Serial.print("Temperatura bmp: ");
  Serial.print(temp);
  Serial.println(" ºC.");

  Serial.print("Presión bmp: ");
  Serial.print(presion);
  Serial.println(" Pa.");

  Serial.print("Altitud bmp: ");
  Serial.print(altitud);
  Serial.println(" metros.");

  Serial.println("-----------------------");  
}
