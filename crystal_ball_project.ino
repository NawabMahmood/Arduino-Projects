#include <LiquidCrystal.h>;
LiquidCrystal lcd(12,11,5,4,3,2);
const int switchpin =6;
int switchstate= 0;
int prevswitchstate = 0;
int reply;
void setup() {
 lcd.begin(16,2);
 pinMode(switchpin,INPUT);
 lcd.print("ask the");
 lcd.setCursor(0,1);
 lcd.print("crystal ball");

}

void loop() {
  switchstate = digitalRead(switchpin);

  if(switchstate != prevswitchstate){

    if(switchstate == LOW){
      reply = random(8);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("the ball says:");
      lcd.setCursor(0,1);

      switch(reply){
        case 0:;
        lcd.print ("yes");
        break;
        case 1:;
        lcd.print("most likely");
        break;
        case 2:;
       lcd.print("certainly");
       break;
       case 3:;
       lcd.print("outlook good");
         break;
         case 4:;
       lcd.print("unsure");
       break;
       case 5:;
         lcd.print("Ask again");
         break;
         case 6:;
       lcd.print("Doubtful");
         break;
         case 7:;
      
           
         lcd.print("no");
         break;
        
      }
      
      
      
      
      }
  }
 prevswitchstate= switchstate;
 print(switchstate);
}
