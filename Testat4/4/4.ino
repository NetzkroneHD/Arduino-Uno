int trigger = 7;
int echo = 8;
int soundPin = 10;

// Schallgeschwindigkeit in der Luft (in cm/ms)
// wird benötigt, um die Laufzeit in eine Entfernung
float speedOfSound = 0.03432;

void setup() {
    pinMode(echo, INPUT);
    pinMode(trigger, OUTPUT);
    pinMode(soundPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {

    digitalWrite(trigger, LOW);
    delay(5);

    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);

    long time = pulseIn(echo, HIGH);

    long distance = (time / 2) * speedOfSound;

    Serial.print("cm: ");
    Serial.println(distance);

    lamp(distance);

    delay(500);
}

void lamp(long distance) {
    int mode = HIGH;
    for(int i = 0; i < distance; i++) {
        digitalWrite(soundPin, mode);
        delay(10);
        if(mode == HIGH) {
            mode = LOW;
        } else {
            mode = HIGH;
        }
    }

}

void sound(long distance) {
    if(distance == 0 || distance >= 15) {
        noTone(soundPin);
    } else {
        tone(soundPin, distance*100);
    }
}
