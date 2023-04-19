const int trigPin = D6;
const int echoPin = D5;
const int ledPin = D0;

// Sound velocity in cm/uS
#define SOUND_VELOCITY 0.034

#define DISTANCE_THRESHOLD 3 // cm

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);

  float distance = duration * SOUND_VELOCITY/2;
  
  Serial.print("Distance (cm): ");
  Serial.println(distance);

  if(distance <= DISTANCE_THRESHOLD) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }
  
  delay(1000);
}