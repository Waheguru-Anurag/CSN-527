// Arduino 1 Code

int buzzerPin = 8;
int pushButtonPin = 4;

int buzzerState = 0;

int lastButtonState = 0;
int buttonState = 0;
int prevTime = 0;
int debounceTime = 50; // milliseconds

void setup()
{
  Serial.begin(9600);

  pinMode(buzzerPin, OUTPUT);
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
        Serial.write('1');
      }
    }
  }

  lastButtonState = buttonReading;
  
  while (Serial.available() > 0)
  { 
    char data = Serial.read();
    
    if (data == '2')
    {
      if(buzzerState == 0) {
      	tone(buzzerPin, 1000);
        Serial.println("Buzzer Beeping !!!!");
      } else {
      	noTone(buzzerPin);
        Serial.println("Buzzer Stopped !!!!");
      }
      
      buzzerState = !buzzerState;
    }
  }
}
