// Arduino 2 Code

int ledPin = 8;
int pushButtonPin = 4;

int ledState = 0;

int lastButtonState = 0;
int buttonState = 0;
int prevTime = 0;
int debounceTime = 50; // milliseconds

void setup()
{
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
}

void loop()
{
  int buttonReading = digitalRead(pushButtonPin);

  if(buttonReading != lastButtonState) {
    prevTime = millis();
  }

  if((millis() - prevTime) >= debounceTime) {
    if(buttonReading != buttonState) {
      buttonState = buttonReading;
      
      if(buttonState == HIGH) {
        Serial.write('2');
      }
    }
  }

  lastButtonState = buttonReading;
  
  while (Serial.available() > 0)
  {
    char data = Serial.read();
    
    if (data == '1')
    {
      if(ledState == 0) {
      	digitalWrite(ledPin, HIGH);
        Serial.println("LED ON");
      } else {
      	digitalWrite(ledPin, LOW);
        Serial.println("LED OFF");
      }
      
      ledState = !ledState;
    }
  }
}
