int ledPin = 2;
int buzzerPin = 8;
int pirSensorPin = 4;

int sensorState = 0;

void setup() {
  Serial.begin(9600);

  pinMode(pirSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int sensorReading = digitalRead(pirSensorPin);

  if(sensorReading == HIGH) {
    if(sensorState == LOW) {
      digitalWrite(ledPin, HIGH);
      tone(buzzerPin, 1000, 5000);

      Serial.println("Motion detected !");

      sensorState = HIGH;
    }
  } else {
    if(sensorState == HIGH) {
      digitalWrite(ledPin, LOW);

      Serial.println("Motion stopped !");

      sensorState = LOW;
    }
  }
}
