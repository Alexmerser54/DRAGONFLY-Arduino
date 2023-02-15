#define ON_PERIOD 1000
#define OFF_PERIOD 500

unsigned long timer;
bool flag;
void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
	timer = millis();
}

void loop()
{
	if (!flag && millis() - timer >= ON_PERIOD) {

		digitalWrite(LED_BUILTIN, HIGH);
		flag = true;
		timer = millis();
	}
	else if (flag && millis() - timer >= ON_PERIOD) {
		digitalWrite(LED_BUILTIN, LOW);
		flag = false;
		timer = millis();
	}
}