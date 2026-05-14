// C++ code
//
const int kPiezoPin = A0;
const int kLed1Pin = 12;
const int kLed2Pin = 10;
const int kLed3Pin = 8;

const int kThresholdLow = 200;
const int kThresholdHigh = 500;

void setup()
{
  pinMode(kLed1Pin, OUTPUT);
  pinMode(kLed2Pin, OUTPUT);
  pinMode(kLed3Pin, OUTPUT);
  pinMode(kPiezoPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int soundValue = analogRead(kPiezoPin);
  Serial.println(soundValue);

  if (soundValue < kThresholdLow)
  {
    digitalWrite(kLed1Pin, HIGH);
    digitalWrite(kLed2Pin, LOW);
    digitalWrite(kLed3Pin, LOW);
  }
  else if (soundValue < kThresholdHigh)
  {
    digitalWrite(kLed1Pin, HIGH);
    digitalWrite(kLed2Pin, HIGH);
    digitalWrite(kLed3Pin, LOW);
  }
  else
  {
    digitalWrite(kLed1Pin, HIGH);
    digitalWrite(kLed2Pin, HIGH);
    digitalWrite(kLed3Pin, HIGH);
  }

  delay(50);
}