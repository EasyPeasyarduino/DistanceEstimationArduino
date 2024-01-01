#include <LiquidCrystal_I2C.h>

const int trigPin = 3;
const int echoPin = 2;

LiquidCrystal_I2C lcd(0x27,20,4);

void setup(){
  Serial.begin(9600);
  lcd.init();
  lcd..backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,High);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  long duration= pulseIn(echoPin,HIGH);
  float distance =duration * 0.0343 / 2;
  //print in Serial Monitor 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");
  //display on LCD
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");

  delay (500);

}