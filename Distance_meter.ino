#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
const int trigPin=8;
const int echoPin=9;
long duration;
int distanceCm;
float distanceInch;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distanceCm=duration*0.034/2;
  distanceInch=duration*0.01330/2;
  lcd.setCursor(0,0);
  lcd.print("DISTANCE:");
  lcd.print(distanceCm);
  lcd.print(" CM  ");
  delay(10);
  lcd.setCursor(0,1);
  lcd.print("DISTANCE:");
  lcd.print(distanceInch);
  lcd.print("INCH");
  delay(10);

}
