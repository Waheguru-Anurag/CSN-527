#include <DHT.h>
#include <Ubidots.h>
#define DHTPIN D5

const char* UBIDOTS_TOKEN = "BBFF-QWVwLk2UWf7kgETCsGoR8bDUs9vWuo";
const char* WIFI_SSID = "...";
const char* WIFI_PASS = "...";

DHT dht(DHTPIN, DHT11);
Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);

void setup(){
	Serial.begin(9600);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  dht.begin();
}

void sendDataToUbidots(float temperature, float humidity) {
  ubidots.add("Temperature", temperature);
  ubidots.add("Humidity", humidity);
  
  bool bufferSent = false;
  bufferSent = ubidots.send();

  if (bufferSent) {
   Serial.println("Values sent by the device");
  }
}

void loop(){
  Serial.print("Temperature = ");
  float temperature = dht.readTemperature();
  Serial.println(temperature);

  Serial.print("Humidity = ");
  float humidity = dht.readHumidity();
  Serial.println(humidity);

  sendDataToUbidots(temperature, humidity);

  delay(5000);
}
