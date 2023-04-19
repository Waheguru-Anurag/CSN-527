#include <Wire.h>
#include <SPI.h>

#include <Adafruit_BMP280.h>

#define BMP_SCK D5
#define BMP_MISO D6
#define BMP_MOSI D7
#define BMP_CS D8

Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO, BMP_SCK); // SPI

void setup() {
  Serial.begin(9600);

  bool status;
  
  status = bmp.begin(118);  

  if (!status) {
    Serial.println("Could not find a valid bmp280 sensor, check wiring!");
    while (1);
  }
}

void loop() { 
  Serial.print("Temperature = ");
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");
  
  Serial.print("Pressure = ");
  Serial.print(bmp.readPressure() / 100.0F);
  Serial.println(" hPa");
  
  Serial.print("Approx. Altitude = ");
  Serial.print(bmp.readAltitude());
  Serial.println(" m");
  
  Serial.println();

  delay(500);
}
