

#include <Servo.h>;
Servo myServo;
#include <LiquidCrystal.h>
#define trigPin 13
#define echoPin 7
#define led 9
#define led2 10
  
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int timer = 0;
int timer2 = 0;
bool racestarted = false;
//SimpleTimer timer;





void setup() {

  myServo.write(180);
 
  delay(5000);
   myServo.write(0);
   delay(2000);
   
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(6,INPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(led, OUTPUT);
    pinMode(led2, OUTPUT);

    myServo.attach(8);
     
    lcd.begin(16,2);
    pinMode(6, INPUT);

    lcd.print("Car #1");
    lcd.setCursor(0,1);
    lcd.print("Car #2");

 //timer.setInterval(1000, DigitalClockDisplay);
}



void loop() {
 long duration, distance;
  digitalWrite(trigPin, LOW); // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH) ;
// delayMicroseconds(1000); - Removed this line
  delayMicroseconds(5); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 7) { // This is where the LED On/Off happens
    digitalWrite(led,HIGH); 
  digitalWrite(led2,LOW);
  racestarted = false;
}
  else {
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
  }
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(0);
  


  
  // put your main code here, to run repeatedly:
  int T=digitalRead(6);
  // Serial.println(racestarted);
//  digitalRead(6);
    
    
  if(T == 1){
    myServo.write(0);
    racestarted=true;
  }
 else {//delay(2000);
   myServo.write(100);
  }



    
  if(racestarted == true){
      timer++;
      timer2 ++;
    } 

    
       
  Serial.println(timer);
  lcd.setCursor(7,2);
  lcd.print(timer);
      
    
  lcd.setCursor(7,0);
  lcd.print(timer2);
  delay(1);
  
}
 







