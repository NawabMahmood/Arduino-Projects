void setup() {
 Serial.begin(9600);
 pinMode(7,INPUT);
 pinMode(9,OUTPUT);

}

void loop() {
  int a = analogRead(A1);
  int S =  digitalRead(7);

  if( S == 1){

    if(a<10){
      digitalWrite(9,1);
    }
    else{ 
      digitalWrite(9,0);
    }
    
  }

else{ 
  digitalWrite(9,0);
  }
}
