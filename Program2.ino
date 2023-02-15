
int modes = 0;
int delaysOn[5] = { 500, 1000, 3000, 4000 };
int delaysOff[5] = { 500, 500, 1500, 3000 };

void setup()
{
	pinMode(3, INPUT_PULLUP);
	pinMode(LED_BUILTIN, OUTPUT);
	attachInterrupt(1, buttonHandler, RISING);
}

void loop()
{
	digitalWrite(LED_BUILTIN, HIGH);
	delay(delaysOn[modes]);
	digitalWrite(LED_BUILTIN, LOW);
	delay(delaysOff[modes]);
}

void buttonHandler() {
	if (modes == 4) modes = 0;
	else modes++;
}