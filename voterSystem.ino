// Author: Nancy 
/*
   The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

*/

#include <LiquidCrystal.h>


const int trigPin = 9;
const int echoPin = 10;

//Initializing variables for metric and imperial values
int distanceCm, distanceInch;



// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


// defines variables
long duration;
int distance;


void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Input
  Serial.begin(9600);       // Starts the serial communication
  lcd.begin(16, 2);
  duration = 0;


}

void loop() {
  // put your main code here, to run repeatedly:
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distanceCm = duration*0.034/2;
  distanceInch = duration*0.0133/2;

  
  // set up the LCD's number of columns and rows:
//  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  // Works needs to be done to properly truncate the number to a int. 
  lcd.print(trunc(distanceCm));
  lcd.print(" ");
  delay(250);
}
