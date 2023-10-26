
const int led = LED_BUILTIN;
const int buttonPin = 11;
const int ledPin = 2;

int buttonState = LOW;
int ledState = LOW;

void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void loop() {
  
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH) {
    ledState = getReversed(ledState);
  }
  digitalWrite(ledPin, ledState);
}

int getReversed(int state) {
  if(state == LOW) {
    return HIGH;
  }
  if(state == HIGH) {
    return LOW;
  }
  
}
