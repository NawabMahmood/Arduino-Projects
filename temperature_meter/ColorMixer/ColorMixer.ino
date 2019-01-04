int redvalue = 0;
int greenvalue = 0;
int bluevalue = 0;

int redsensorvalue = 0;
int greensensorvalue = 0;
int bluesensorvalue = 0; 

 const int redport = 10;
 const int greenport = 8;
 const int blueport = 9;

void setup() {
 
  Serial.begin(9600);
  pinMode(redport, OUTPUT);
  pinMode(greenport, OUTPUT);
  pinMode(blueport, OUTPUT);
}


void loop() {
const int redanalogport = A5;
const int greenanalogport = A2;
const int bluenalogport = A0;

redsensorvalue = analogRead(redanalogport);
delay(50);
greensensorvalue = analogRead(greenanalogport);
delay(50);
bluesensorvalue = analogRead(bluenalogport);

redvalue = redsensorvalue/4;
greenvalue = greensensorvalue/4;
bluevalue = bluesensorvalue/4;

analogWrite(redport, redvalue);
analogWrite(greenport, greenvalue);
analogWrite(blueport, bluevalue);







}
