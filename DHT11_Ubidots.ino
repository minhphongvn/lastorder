#include “DHT.h”
#include “UbidotsMicroESP8266.h”
#define DHTPIN 4//pin sensor DHT
#define TOKEN “BBFF-afbeEG26W0j4QCDaIOzeWB7lsxF8GP” //token anda
#define ssid “@wifi.id”
#define psswd “252525251”
DHT dht(DHTPIN,DHT11);
Ubidots client(TOKEN);
unsigned long last =0;
void setup() {
Serial.begin(9600);
dht.begin();
delay(20);
client.wifiConnection(ssid,psswd); // klau ssid memakai pass
// client.wifiConnection(ssid,NULL); // klau ssid tdk memakai pass
}
void loop() {
if(millis()-last>1000){
float hum = dht.readHumidity();
float temp = dht.readTemperature();
last=millis();
client.add(“kelembaban”,hum);
client.add(“Temperature”,temp);
client.sendAll(true);
}
}
