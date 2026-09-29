#include <DHT.h>
#define DHTPIN 11
#define DHTTYPE DHT11
DHT myDHT(DHTPIN,DHTTYPE);
float tempCelcuis;
int duration = 500;
int br = 9600;
int ledPin= 4;
int buzzerPin = 8 ;
float Humidity ;
float HIC;
void setup() {
  // put your setup code here, to run once:
pinMode(ledPin,OUTPUT);
pinMode(buzzerPin,OUTPUT);
  Serial.begin(br);
  myDHT.begin();
  
  

}

void loop() {
  // put your main code here, to run repeatedly:
tempCelcuis = myDHT.readTemperature(false);
Humidity = myDHT.readHumidity();
HIC = myDHT.computeHeatIndex(false);
Serial.println("The Temperature is : "+ String(tempCelcuis)+" C" + "   The Humdity  is : "+String(Humidity)+ " %" +"  It feels like " +String(HIC)+" C");
if(isnan(tempCelcuis) || isnan(Humidity) || isnan(HIC)){
  Serial.println("Cant read data from DHT11");
  return;
}
if(tempCelcuis >= 26){
  digitalWrite(ledPin,HIGH);
  digitalWrite(buzzerPin,HIGH);
  Serial.println("Temperature is too high");

}
else{
  digitalWrite(ledPin,LOW);
  digitalWrite(buzzerPin,LOW);
}
delay(duration);
}