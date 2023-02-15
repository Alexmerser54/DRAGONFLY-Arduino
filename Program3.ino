#define BUTTON_DELAY 600

bool flag = false;
unsigned long timer;
void setup()
{
	pinMode(3, INPUT_PULLUP);
	attachInterrupt(1, buttonHandler, FALLING);
	Serial.begin(9600);
	timer = millis();
}

void loop()
{
	if (flag && !digitalRead(3) && millis() - timer	>= BUTTON_DELAY) {
		Serial.println("I am pressed!");
		flag = false;
		timer = millis();

	}
}

void buttonHandler() {
	flag = true;
}