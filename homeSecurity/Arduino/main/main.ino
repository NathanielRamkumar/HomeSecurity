// defines pins numbers
const int trigPin = 13;
const int echoPin = 12;
const int buzzerPin = 2;
const int LEDpin = 3;
const int buttonPin = 11;
const int statusPin = 4;
// defines variables
long duration;
int distance;
bool status = false;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(buzzerPin, OUTPUT);
  pinMode(LEDpin,OUTPUT);
  pinMode(buttonPin,INPUT);
  Serial.begin(9600); // Starts the serial communication
  digitalWrite(statusPin, LOW);
  bool playBuzzer = 1;
}
void loop() {

  digitalWrite(trigPin, LOW); // Not my code
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance < 30) {
    delay(1000);
    if (distance < 60) {
      if (Serial.peek() == -1) {
        digitalWrite(buzzerPin, HIGH);
      }
      digitalWrite(LEDpin,HIGH);
      Serial.println("SUS");
    }
  }

  delay(15);

}




