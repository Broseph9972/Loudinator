// C++ code
//
const int kPiezoPin = A0;
const int kLed1Pin = 12;
const int kLed2Pin = 10;
const int kLed3Pin = 8;

const int kNoiseFloor = 250;
const int kThresholdGreen = 300;
const int kThresholdYellow = 500;
const int kThresholdRed = 900;
const unsigned long kSampleIntervalMs = 50;

int gLastSoundValue = 0;
unsigned long gLastSampleMs = 0;

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
  unsigned long nowMs = millis();

  if (nowMs - gLastSampleMs >= kSampleIntervalMs)
  {
    gLastSampleMs = nowMs;
    gLastSoundValue = analogRead(kPiezoPin);
    Serial.println(gLastSoundValue);

    int adjustedValue = gLastSoundValue;
    if (adjustedValue <= kNoiseFloor)
    {
      adjustedValue = 0;
    }

    if (adjustedValue < kThresholdGreen)
    {
      digitalWrite(kLed1Pin, LOW);
      digitalWrite(kLed2Pin, LOW);
      digitalWrite(kLed3Pin, LOW);
    }
    else if (adjustedValue < kThresholdYellow)
    {
      digitalWrite(kLed1Pin, HIGH);
      digitalWrite(kLed2Pin, LOW);
      digitalWrite(kLed3Pin, LOW);
    }
    else if (adjustedValue < kThresholdRed)
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
  }
}