int echo = 8;
int trigger = 7;

// Schallgeschwindigkeit in der Luft (in cm/ms)
// wird benötigt, um die Laufzeit in eine Entfernung
float speedOfSound = 0.03432;

void setup() {
    pinMode(echo, INPUT);
    pinMode(trigger, OUTPUT);
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
    delay(500);



    Serial.print("cm: ");
    Serial.println(distance);

}