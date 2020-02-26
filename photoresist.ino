#include <Servo.h>
Servo servo;
int photo = 0; // light sensor overall reading
float freq = 0; // frequency variable
void setup() {
Serial.begin(9600);
servo.attach(8);
servo.write(10);
pinMode(9, OUTPUT);
}


void loop() {
  int pot = analogRead(A1);
  photo = analogRead(A0); //read both photoresistors
  //Serial.println(photo);
  int potPos = map(pot, 0, 1024, 0, 255);
  int tonez = map(photo, 130, 810, 100, 1000);
  Serial.println(potPos);
  if(tonez > 700){
    servo.write(90);
  } 
  else if (tonez > 400 && tonez < 700) {
    servo.write(45);
    
  }
  else{
    servo.write(-90);
  }
 analogWrite(9,potPos);
}
