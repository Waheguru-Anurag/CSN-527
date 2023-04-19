int ledPin = 2;

int ledState = LOW;
int prevTime = 0;
int interval = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int currTime = millis();
  
  if((currTime - prevTime) >= interval) {
   	prevTime = currTime;
    
    if(ledState == LOW) {
    	ledState = HIGH;
    } else {
      	ledState = LOW;
    }
    
    digitalWrite(ledPin, ledState);
  }
}