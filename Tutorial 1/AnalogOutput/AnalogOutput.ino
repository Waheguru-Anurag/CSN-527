int ledPin=5;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  for(double value=0; value<=255; value+=10) {
  	analogWrite(ledPin, int(value)); 
    Serial.print("Brightness ");
    Serial.print((value/255)*100);
    Serial.println("%");
    delay(100);
  }
  
  for(double value=255; value>=0; value-=10) {
  	analogWrite(ledPin, int(value)); 
    Serial.print("Brightness ");
    Serial.print((value/255)*100);
    Serial.println("%");
    delay(100);
  } 
}