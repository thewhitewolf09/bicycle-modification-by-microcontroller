/*
 Sumit Nirmal
 20CE10075
 Indian Institute Of Technology Kharagpur
 DIY Project
 Group No. 21
*/
#include <LiquidCrystal.h> // library for LCD 16*2 Display
LiquidCrystal lcd(12,11,5,4,3,2); // Declaration of all digital pins of lcd
display
#define pi 3.1416
int hall_sensor = 6; // Declaration of hall effect sensor && digital
output at pin 6
int state1=0;
int state2=0;
int laststate = 0;
int counter = 0;
int timer1=0;
int timer2=0;
int timer3=0;
float v=0; // velocity
float d = 0.72; //diameter of bicycle wheel
float circumference = d*pi;
int brakelight = 8;
void setup()
{
 pinMode(hall_sensor,INPUT);
 pinMode(brakelight,OUTPUT);
 lcd.begin(16,2);
 lcd.clear();
 lcd.print("Let's");
 lcd.setCursor(0,1);
 lcd.print("Ride");
 delay(2000);
}
void loop()
{
 if(2>v) // minimum thresold speed (2 km/hr) for brakelight
 {
 digitalWrite(brakelight,HIGH);
 }
 if(2<v)
 {
 digitalWrite(brakelight,LOW);
 }
state1=digitalRead(hall_sensor); //Hall_effect sensor give input value 0 when
it detect magnetic field
delay(10);
state2=digitalRead(hall_sensor);
 if (state1 == state2) {
 if (state1 != laststate){
 if (state1 == HIGH) {
 counter = counter + 1;
 velocity();
 }
 }
 }
 laststate = state1;
 LCD();
}
void velocity(){
 if(counter%2 == 0){
 timer1=millis();
 }else{
 timer2=millis();
}
 timer3=abs(timer1-timer2); // timer3 count the time of one rotation and
use absolute value function (abs();)
 v = circumference/(timer3)*1000*(18/5);
}
void LCD(){
 lcd.clear();
 lcd.print("Sumit Nirmal");
 lcd.setCursor(0,1);
 lcd.print("Speed=");
 lcd.print(v);
 lcd.print("Km/hr");
 return;
}