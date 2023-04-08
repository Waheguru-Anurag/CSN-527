int inputPin = 2;
int prevButtonState = 0;

void setup()
{
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int buttonState = digitalRead(inputPin);

  if(prevButtonState != buttonState) {
    if (buttonState == HIGH) {
      Serial.println("Button is Pressed");
      delay(1000);
    } else {
      Serial.println("Button is Released");
      delay(1000);
    }

    prevButtonState = buttonState;
  }
}