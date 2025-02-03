
const int led = 9;
int brightness = 0;
int fadeAmount = 8;
bool ledState1 = LOW;
bool ledState2 = HIGH;

int appState = 0;
int counter = 0;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(19200);
}

void allume() {
  int delayAllume = 2000;
  if (appState == 0) {
    Serial.println("Allume - 6334158");
    digitalWrite(led, ledState2);
    delay(delayAllume);

    counter++;

    if (counter == 1) {
      counter = 0;
      appState = 1;
      digitalWrite(led, ledState1);
      delay(100);
      Serial.println("Clignotement - 6334158");
    }
  }
}
void clignotement() {
  int delayClignotement = 250;
  if (appState == 1) {
    digitalWrite(led, ledState2);
    delay(delayClignotement);
    digitalWrite(led, ledState1);
    delay(delayClignotement);

    counter++;
    if (counter == 4) {
      counter = 0;
      appState = 2;
      Serial.println("Variation - 6334158");
    }
  }
}
void variation() {
  int delayVariation = 40;
  if (appState == 2) {

    analogWrite(led, brightness);

    brightness = brightness + fadeAmount;

    if (brightness >= 255) {

      brightness = 0;
      counter = 0;
      appState = 3;
    }
    delay(delayVariation);

    counter++;
  }
}
void eteint() {
  int delayEteint = 2000;
  if (appState == 3) {
    Serial.println("Éteint - 6334158");
    digitalWrite(led, ledState1);
    delay(delayEteint);

    counter++;
    if (counter == 2) {
      counter = 0;
      appState = 0;
    }
  }
}

void loop() {

  allume();
  clignotement();
  variation();
  eteint();
}
