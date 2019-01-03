

const int sensorPin = A0;
int basetemp = 50.0;



void setup(){
  Serial.begin(9600);
for (int pinNumber = 2; pinNumber <8; pinNumber ++){
  pinMode(pinNumber, OUTPUT);
  digitalWrite(pinNumber, LOW);
}
}

void loop() {
  int sensorIs = analogRead(sensorPin);
  Serial.print("Sensors Value");
  Serial.print(sensorIs);
  //sensorIs is reading the heat sensor and saving it in the variable;
    
float voltage = (sensorIs/1024.0)*5.0;
// math is done to take sensor reading and convert it into the unit Volts in  the variable for a easy way to measure:
  Serial.print("Volts:");
Serial.print(voltage);

float temperature = (((voltage - .5)* 100) * 1.8 )+ 32;
// Math is done to convert voltage to Celsius, and then convert Celsius to Fahrenheit and saving it into variable temperature;
  Serial.print("temperature in Fahrenheit:");
Serial.println(temperature);

if(temperature < basetemp){
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(7,LOW);
//  if temp is lower then the base temp (50.0 F degrees Fahrenheit then one specific light turns on in port 3;

}
else if(temperature >= basetemp  && temperature < basetemp + 15){
    digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(7,LOW);
//  if temp is greater or equal to 50.0 F but less then 65.0 F one specific light turns on in port 2; 
basetemp = 65.0;
}
else if(temperature >= basetemp +15 && temperature < basetemp + 10){
   digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(7,HIGH);
  //  if temp is greater or equal to 65.0 F but less then 75.0 F one specific light turns on in port 2; 
  basetemp = 75.0;
}  
else if( temperature >= basetemp ){
     digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(7,LOW);
//  if temp is higher then 75.0 F the no lights are on;
}
delay(10);
}
