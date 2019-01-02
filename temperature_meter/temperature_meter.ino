

const int sensorPin = A0;
const int basetemp = 20.0;



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
    
float voltage = (sensorIs/1024.0)*5.0;
  Serial.print("Volts:");
Serial.print(voltage);

float temperature = (voltage - .5)* 100;
  Serial.print("temperature in Celsius:");
Serial.println(temperature);

if(temperature < basetemp){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(7,LOW);

}
else if(temperature >= basetemp +2 && temperature < basetemp + 4){
    digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(7,LOW);
}
else if(temperature >= basetemp +4 && temperature < basetemp + 6){
   digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(7,LOW);
}  
else if( temperature >= basetemp + 6){
     digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(7,HIGH);
}
delay(1);
}
