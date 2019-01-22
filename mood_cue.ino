#include <Servo.h>;

Servo myservo;
int potValue;
int angle;


void setup() {
  myservo.attach(9);
  Serial.begin(9600);

}

void loop() {
  potValue = analogRead(A0);
//  reads analog port and saves it into potValue;


  
  Serial.print("pentometer value is");
  Serial.println(potValue);
//  prints the number on computer;
  angle = map(potValue, 0,1023,0,179);
//  map function converts the potValue number inbetween 0-1023 into between 0-179 and saves it into angle;
  Serial.print ( "Angle is");
  Serial.println(angle);
  myservo.write(angle);
//   writes number saved in angle to tell motor how far to rotate inbetween 0-179; 
  delay(20);

}
