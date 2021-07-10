#include "DHT.h";
#include <WiFi.h>;

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

float temp;
float hum;

void setup() {
  Serial.begin(9600);
  Serial.println();

  dht.begin();

}

void loop() {
  hum = dht.readHumidity();
  temp = dht.readTemperature();

  if (isnan(temp) || isnan(hum)) {
    Serial.println(F("Error: Failed to read from DHT sensor!"));
  } else {
    Serial.printf("Temp: %.2f \tHum: %.2f\n", temp, hum);
  }

  delay(2000);
}
