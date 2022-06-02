SerialLogHandler logHandler;
int led = D7;

String InputTime;
String TimeHour;

void setup()
{
    Time.zone(+10);
    
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);

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
        Particle.publish("Data", InputTime);
        //Particle.publish("Time", TimeHour);
        if(TimeHour == InputTime)
        {
            digitalWrite(led, HIGH);
            delay(10000);
            digitalWrite(led, LOW);
            delay(1000);
        }
        else
        {
            break;
        }
    }
}