#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

const char *ssid = "...";
const char *password = "...";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Wifi Connected");

  timeClient.begin();
  // Set offset time in seconds to adjust for your timezone
  // GMT +1 = 3600
  // GMT 5:30 = 3600 * 5.5
  timeClient.setTimeOffset(19800);
}

void loop() {
  timeClient.update();
  
  String formattedTime = timeClient.getFormattedTime();

  time_t epochTime = timeClient.getEpochTime();
  struct tm *ptm = gmtime ((time_t *)&epochTime); 
  int day = ptm->tm_mday;
  int month = ptm->tm_mon+1;
  int year = ptm->tm_year+1900;

  String timeString = String(year) + "-" + String(month) + "-" + String(day) + " " + formattedTime + "+05:30";

  Serial.println(timeString);

  delay(2000);
}
