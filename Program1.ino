#define ON_PERIOD 2000
#define OFF_PERIOD 4000

void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
	digitalWrite(LED_BUILTIN, HIGH);
	
}

void loop()
{

	digitalWrite(LED_BUILTIN, HIGH);
	delay(ON_PERIOD);
	digitalWrite(LED_BUILTIN, LOW);
	delay(OFF_PERIOD);

}