int trigger = 7;
int echo = 8;
int soundPin = 10;

float speedOfSound = 0.03432;

void setup() {
    pinMode(echo, INPUT);
    pinMode(trigger, OUTPUT);
    pinMode(soundPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    //Trigger steht die ganze Zeit auf LOW, braucht den Abstand nach der Messung
    digitalWrite(trigger, LOW);
    delay(20);

    //Trigger wird auf HIGH gesetzt um die Messung zu starten
    digitalWrite(trigger, HIGH);
    //Das HIGH des Senders
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);

    //Wartet darauf dass der PIN von LOW auf HIGH geht 
    //und misst die Zeit die der Pin braucht um wieder auf LOW zu gehen
    long time = pulseIn(echo, HIGH);

    double distance = (time / 2) * speedOfSound;

    Serial.print("cm: ");
    Serial.println(distance);

    sound(distance);

    delay(500);
}

void sound(long distance) {
    if(distance == 0 || distance >= 15) {
        noTone(soundPin);
    } else {
        tone(soundPin, distance*100);
    }
}
