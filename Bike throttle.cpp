
int throttle = A0;
int Hall = 13;
int data = 170;
int datah = 0;

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
  data = 170;

  // Make throttle available when hall sensor sensor magnets/pedeling
  if (temp > 1 || digitalRead(Hall) == 0)
  {
    tempPin = PotentiometerPin;
    data = analogRead(tempPin);
  }
  else
  {
    tempPin = 170;
  }
  //Serial.println(digitalRead(Hall));
  //data = analogRead(tempPin);
  Serial.println(data);
  esc.writeMicroseconds(map(analogRead(data), 0, 1023, 1000, 2000));

  // Count magnet passes every 500 ms
  if (millis() > next)
  {
    temp = count;
    count -= temp;
    next += 500;
  }
}

void magnet_detect()
{
  count++;
}