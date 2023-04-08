int ledPin=4;

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println("LED is ON");
  digitalWrite(ledPin, HIGH);
  delay(100);
  
  Serial.println("LED is OFF");
  digitalWrite(ledPin, LOW);
  delay(100);
}