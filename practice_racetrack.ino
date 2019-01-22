#include <Servo.h>;
#include <LiquidCrystal.h>;

LiquidCrystal lcd(12,11,4,3,2);


Servo myservo;
const int switchs = 6;
int timer = 0;
bool racestarted=false;

void setup() {
  lcd.begin(16,2);
//  tells how big window is for words;
  myservo.attach(9);
  Serial.begin(9600);
  pinMode(2,INPUT);
  lcd.print("time is:");


}

void loop() {


int switchstate = digitalRead(switchs);
//Serial.println(switchstate);
if(switchstate == 1){
  racestarted=true;
 
  myservo.write(0);
   
  
}
else
{ myservo.write(100);}



    
    
    
    if(racestarted == true){
    
        timer++;
        Serial.println(timer);
        lcd.setCursor(0,1);
        lcd.print(timer);
        delay(1000);
        
    }
}

  

