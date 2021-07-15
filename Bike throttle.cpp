
int throttle = A0;
int halls = A5;
int data = 0;
int datah = 0;

#include <Servo.h>

const uint8_t VescOutputPin = 5;

const uint8_t PotentiometerPin = A0;
unsigned int tempPin = PotentiometerPin;
Servo esc;

//
volatile unsigned int count = 0;
unsigned long next = 100;
unsigned int temp = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(halls, INPUT);

  esc.attach(VescOutputPin);

  esc.writeMicroseconds(1500);

  //

  attachInterrupt(digitalPinToInterrupt(2), magnet_detect, RISING);
}

void loop()
{
  data = analogRead(tempPin);
  datah = analogRead(halls);
  //Serial.print("Sensor data:");
  if (count > 1)
  {
    Serial.println(data);
    esc.writeMicroseconds(map(analogRead(PotentiometerPin), 0, 1023, 1000, 2000));
  }
  else
  {

    tempPin = 170;
    Serial.println(tempPin);
  }

  //Serial.println(datah);

  //
  if (millis() > next)
  {
    temp = count;
    //Serial.println(count);
    count -= temp;
    next += 1500;
  }
}

void magnet_detect()
{
  count++;
}