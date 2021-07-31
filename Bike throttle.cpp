int throttle = A0;
int Hall = 13;
int data = 170;

// Interval is how long we wait
int interval = 1000;
// Tracks the time since last event fired
unsigned long previousMillis = 0;

#include <Servo.h>

const uint8_t VescOutputPin = 5;
const uint8_t PotentiometerPin = A0;
unsigned int tempPin = PotentiometerPin;
Servo esc;

volatile unsigned int count = 0;
unsigned long next = 100;
unsigned int temp = 0;

void setup()
{
  pinMode(Hall, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), magnet_detect, RISING);

  esc.attach(VescOutputPin);
  esc.writeMicroseconds(1500);
}

void loop()
{

  // Set throttle at 0 (170)
  data = 160;

  // Get snapshot of time
  unsigned long currentMillis = millis();
  if (temp > 0)
  {
    // How much time has passed, accounting for rollover with subtraction!
    if ((unsigned long)(currentMillis - previousMillis) >= interval)
    {
      // It's time to do something!

      // Use the snapshot to set track time until next event
      previousMillis = currentMillis;
    }

    if (temp != count)
    {
      previousMillis = currentMillis;
    }
  }

  unsigned long throttleInterval = currentMillis - previousMillis;
  if (throttleInterval > interval)
  {
    throttleInterval = interval;
  }
  //Serial.println(throttleInterval);
  //Serial.println(digitalRead(Hall));

  ///////////////////////////////////////
  // Make throttle available when hall sensor sensor magnets/pedeling
  if (throttleInterval < 1000)
  {
    tempPin = PotentiometerPin;
    data = analogRead(tempPin);
  }
  else
  {
    tempPin = 160;
  }
  //////////////////////////////////////

  //data = analogRead(tempPin);
  Serial.println(data);
  esc.writeMicroseconds(map(analogRead(data), 0, 1023, 1000, 2000));

  // Count magnet passes every 500 ms
  if (millis() > next)
  {
    temp = count;
    count -= temp;
    //next += 500;
  }
  //Serial.println(temp);
}

void magnet_detect()
{
  count++;
}