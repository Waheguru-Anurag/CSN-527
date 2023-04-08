int redPin = 11;
int greenPin = 9;
int bluePin = 10;

int const MAX_BRIGHTNESS = 255;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // a. Initialize
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);

  // b. Increase the brightness of R from 0 to 100% in steps.
  for(int value=0; value<=MAX_BRIGHTNESS; value +=5) {
    analogWrite(redPin, value);
    delay(100);
  }
}

void loop() {
  // c.
  for(int value=MAX_BRIGHTNESS; value>=0; value -=5) {
    analogWrite(redPin, value);
    analogWrite(greenPin, MAX_BRIGHTNESS-value);
    delay(100);
  }

  // d.
  for(int value=MAX_BRIGHTNESS; value>=0; value -=5) {
    analogWrite(greenPin, value);
    analogWrite(bluePin, MAX_BRIGHTNESS-value);
    delay(100);
  }

  // e.
  for(int value=MAX_BRIGHTNESS; value>=0; value -=5) {
    analogWrite(bluePin, value);
    analogWrite(redPin, MAX_BRIGHTNESS-value);
    delay(100);
  }
}
