int redvalue = 0;
int greenvalue = 0;
int bluevalue = 0;
//used for saving information for when the sensor values are divided by 4;
int redsensorvalue = 0;
int greensensorvalue = 0;
int bluesensorvalue = 0; 
//used for saving information from analog ports;

 const int redport = 10;
 const int greenport = 8;
 const int blueport = 9;
// digital ports being used

void setup() {
 
  Serial.begin(9600);
  pinMode(redport, OUTPUT);
  pinMode(greenport, OUTPUT);
  pinMode(blueport, OUTPUT);
//  telling that the digital ports will put out information;
}


void loop() {
const int redanalogport = A5;
const int greenanalogport = A2;
const int bluenalogport = A0;
//analog ports being used;
// using const int so the numbers cant change

redsensorvalue = analogRead(redanalogport);
//saving light sensors reading for red port into red sensor value;
delay(50);
greensensorvalue = analogRead(greenanalogport);
//same as above
delay(50);
bluesensorvalue = analogRead(bluenalogport);
//same as above

redvalue = redsensorvalue/4;
greenvalue = greensensorvalue/4;
bluevalue = bluesensorvalue/4;
//for analogWite have to divide sensor values by 4 because before they hold a value between 0-1023 and needs to be brought down between 0-255 for the duty cycle to declare how bright each color will shine:

analogWrite(redport, redvalue);
analogWrite(greenport, greenvalue);
analogWrite(blueport, bluevalue);

//writes out which digital port it is writing to and what the brightmess of the color or called duty cycle will be;





}
