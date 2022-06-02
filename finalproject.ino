//All
int led = D7;

//Motion Sensor
const int trigPin = 3; 
const int echoPin = 2;

float duration, distance; 

float motionRequirements;

//Timing System
SerialLogHandler logHandler;

String InputTime;
String TimeHour;

void setup() 
{
    //All
    pinMode(trigPin, INPUT_PULLUP);
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
    
    //Motion Sensor
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); 
    Serial.begin(9600);    
    
    //Timing System
    Time.zone(+10);
    Particle.subscribe("0", loop, "e00fce68239f24b79547c6ab");
    Particle.subscribe("1", loop, "e00fce68239f24b79547c6ab");
    Particle.subscribe("2", loop, "e00fce68239f24b79547c6ab");
    Particle.subscribe("3", loop, "e00fce68239f24b79547c6ab");
    Particle.subscribe("4", loop, "e00fce68239f24b79547c6ab");
    Particle.subscribe("5", loop, "e00fce68239f24b79547c6ab");
    Particle.subscribe("6", loop, "e00fce68239f24b79547c6ab");
    Particle.subscribe("7", loop, "e00fce68239f24b79547c6ab");
    Particle.subscribe("8", loop, "e00fce68239f24b79547c6ab");
    Particle.subscribe("9", loop, "e00fce68239f24b79547c6ab");
    Particle.subscribe("10", loop, "e00fce68239f24b79547c6ab");
    Particle.subscribe("11", loop, "e00fce68239f24b79547c6ab");
    Particle.subscribe("12", loop, "e00fce68239f24b79547c6ab");
    Particle.subscribe("13", loop, "e00fce68239f24b79547c6ab");
    Particle.subscribe("14", loop, "e00fce68239f24b79547c6ab");
    Particle.subscribe("15", loop, "e00fce68239f24b79547c6ab");
    Particle.subscribe("16", loop, "e00fce68239f24b79547c6ab");
    Particle.subscribe("17", loop, "e00fce68239f24b79547c6ab");
    Particle.subscribe("18", loop, "e00fce68239f24b79547c6ab");
    Particle.subscribe("19", loop, "e00fce68239f24b79547c6ab");
    Particle.subscribe("20", loop, "e00fce68239f24b79547c6ab");
    Particle.subscribe("21", loop, "e00fce68239f24b79547c6ab");
    Particle.subscribe("22", loop, "e00fce68239f24b79547c6ab");
    Particle.subscribe("23", loop, "e00fce68239f24b79547c6ab");
}


void loop(const char *event, const char *data)
{
    for(; ;)
    {
        InputTime = data;
        TimeHour = Time.hour();
        motionRequirements = 50;
        Particle.publish("Data", InputTime);

        //Motion Sensor
        digitalWrite(trigPin, LOW); 
        delayMicroseconds(2); 
        digitalWrite(trigPin, HIGH); 
        delayMicroseconds(10); 
        digitalWrite(trigPin, LOW); 
        duration = pulseIn(echoPin, HIGH); 
        distance = (duration*.0343)/2; 
        
        if(TimeHour == InputTime)
        {
            delay(10000);
            if(distance < motionRequirements)
            {
                Particle.publish("50", String(50));
                Particle.publish("Distance", String(distance));
                Particle.publish("LIFX_TURN_ON_BEDROOM");
                digitalWrite(led, HIGH);
                delay(100000);
                digitalWrite(led, LOW);
                Particle.publish("LIFX_TURN_ON_BEDROOM");
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
        delay(1000);
    }
}
