int ledPin = 2;
int buttonPin = 4;

int ledState = 0;
int lastButtonState = 0;
int buttonState = 0;

int lastUpdateTime = 0;
int debounceDelay = 50;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int buttonReading = digitalRead(buttonPin);

  if (buttonReading != lastButtonState) {
    lastUpdateTime = millis();
  }

  if((millis() - lastUpdateTime) > debounceDelay) {
    if(buttonReading != buttonState) {
      buttonState = buttonReading;

      if(buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }

  digitalWrite(ledPin, ledState);
  lastButtonState = buttonReading;
}
