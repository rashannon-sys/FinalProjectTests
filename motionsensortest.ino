const int trigPin = 3;
const int echoPin = 2;
int led = D7;

float duration, distance;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (duration*.0343)/2;
    Particle.publish("Distance", String(distance));
    Particle.publish("50", String(50));
    if(String(distance) <= String(50))
    {
        Particle.publish("LIFX_TURN_ON_BEDROOM");
        digitalWrite(led, HIGH);
        delay(100000);
        digitalWrite(led, LOW);
        delay(1000);
    }
    delay(1000);
}