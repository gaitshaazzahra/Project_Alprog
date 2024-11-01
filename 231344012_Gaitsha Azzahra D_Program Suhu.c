#include <DHT.h> 
#define DHTPIN 2 
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE); 

float humi, temp;

void setup()
{
    
  Serial.begin(9600); 
  delay(10);  
}

void loop()
{
  humi = dht.readHumidity();
  temp = dht.readTemperature();
  if (isnan(humi) || isnan(temp)) { 
    Serial.println("DHT11 tidak terbaca... !");
    return;
  }
  else{
  Serial.print("Suhu=");  
  Serial.print(temp);     
  Serial.println("C");   
  Serial.print("Humi=");  
  Serial.print(humi);     
  Serial.println("%RH");  
  }
  delay(1000);            
}