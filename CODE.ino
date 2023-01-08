int enablePin = 11;

int in1Pin = 10;

int in2Pin = 9;

int switchPin = 7;

int potPin = 0;

int statusPin= 13;

int LED_PIN = 6;

void setup()

{

pinMode(in1Pin, OUTPUT);

pinMode(in2Pin, OUTPUT);

pinMode(enablePin, OUTPUT);

pinMode(switchPin, INPUT_PULLUP);

pinMode(statusPin,OUTPUT);

pinMode(LED_PIN, OUTPUT);

}

void loop()

{

digitalWrite(13,HIGH);

int speed = analogRead(potPin) / 4;

boolean reverse = digitalRead(switchPin);

setMotor(speed, reverse);
  
int potentiometerValue = analogRead(A1);

int brightness = map(potentiometerValue, 0, 1023, 0, 255);
 
analogWrite(LED_PIN, brightness);

}

void setMotor(int speed, boolean reverse)

{

analogWrite(enablePin, speed);

digitalWrite(in1Pin, ! reverse);

digitalWrite(in2Pin, reverse);

}

