#include <LiquidCrystal.h>
const int echo = 3, Trig = 7;
long duration=0, cm=0;
long WaterLevel=0;
// include the library code:


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8,9,10,11,12,13);

void setup() {
  lcd.begin(16, 2);
  
// initialize serial communication:
Serial.begin(9600);
pinMode(Trig, OUTPUT);
pinMode(echo, INPUT);

}
void loop()
{
// establish variables for duration of the ping,
// and the distance result in inches and centimeters:

// The PING))) is triggered by a HIGH pulse of 10 microseconds.
// Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
digitalWrite(Trig, LOW);
delayMicroseconds(2);
digitalWrite(Trig, HIGH);
delayMicroseconds(10);
digitalWrite(Trig, LOW);
// The echo pin is used to read the signal from the PING))): a HIGH
// pulse whose duration is the time (in microseconds) from the sending
// of the ping to the reception of its echo off of an object.
duration = pulseIn(echo, HIGH);
// convert the time into a distance
cm = microsecondsToCentimeters(duration);

//Serial.println(cm);
cm=cm-22;
if(cm<0)
cm=0;
//Serial.println(cm);
delay(200);
WaterLevel=1013-((3.14*55*55*cm)/1000);
lcd.setCursor(0,0);
lcd.print("Water Level: ");
delay(300);
lcd.setCursor(0, 1);
lcd.print(WaterLevel);
lcd.print("  Liters ");
delay(50000);
WaterLevel=0;
cm=0;
duration=0;
}
long microsecondsToCentimeters(long microseconds)
{
// The speed of sound is 340 m/s or 29 microseconds per centimeter.
// The ping travels out and back, so to find the distance of the
// object we take half of the distance travelled.
return microseconds / 29 / 2;
}
