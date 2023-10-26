
const int led = LED_BUILTIN;
const int buttonPin = 11;
const int ledPin = 2;

int state = LOW;

void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void loop() {
  
  state = digitalRead(buttonPin);

  if (state == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  
}
