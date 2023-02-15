int modes;
int delaysOn[5] = { 400, 1000, 3000, 4000 };
int delaysOff[5] = { 400, 500, 1500, 3000 };

unsigned long timer;
bool flag;
void setup()
{
	pinMode(3, INPUT_PULLUP);
	pinMode(LED_BUILTIN, OUTPUT);
	attachInterrupt(1, buttonHandler, FALLING);
	modes = 0;
	timer = millis();
}

void loop()
{

	if (!flag && millis() - timer >= delaysOff[modes]) {
		digitalWrite(LED_BUILTIN, HIGH);
		flag = true;
		timer = millis();
	}
	else if (flag && millis() - timer >= delaysOn[modes]) {
		digitalWrite(LED_BUILTIN, LOW);
		flag = false;
		timer = millis();
	}
	
}

void buttonHandler() {

		if (modes == 4) modes = 0;
		else modes++;
}