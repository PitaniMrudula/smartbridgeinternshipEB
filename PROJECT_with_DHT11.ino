#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include<LiquidCrystal.h>
#include <ThingSpeak.h> 
#include <Adafruit_Sensor.h>
#include <DHT.h>
#define DHTTYPE    DHT11  
#define DHTPIN  34    
DHT dht(DHTPIN,DHTTYPE);

 float t = dht.readTemperature();
 float h= dht.readHumidity();


WiFiClient client;
WiFiServer server(80);
const char* ssid     = "chandu"; 
const char* password = "chandu26"; 
float temp_celsius = 0;
float temp_fahrenheit = 0;
const int rs=13, en=12, d4=14, d5=27, d6=26, d7=25;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

unsigned long myChannelNumber = 787435;  
const char * myWriteAPIKey = "N8M3DUOZFX1N2UQW";  
String readDHTTemperature()
{
  
  float t = dht.readTemperature();
  }

String readDHTHumidity()
{
  
  float h = dht.readHumidity();
  
}


void setup() 
{
  
   dht.begin();
   lcd.begin(16, 2);
   Serial.begin(115200);
   pinMode(34, INPUT); 
   pinMode(4,OUTPUT);  
   Serial.println();
   Serial.println();
   Serial.print("Connecting to ");
   Serial.println(ssid);
   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED)
   {
    delay(500);
    Serial.print(".");
   }
   Serial.println("");
   Serial.println("WiFi is connected");
   server.begin();
   Serial.println("Server started");
   Serial.println(WiFi.localIP());
   ThingSpeak.begin(client); 
}
void loop()
{
 dht34();
 motor();
 lcd16();
 static boolean data_state = false; 
 float temperature= t;
 ThingSpeak.writeField(myChannelNumber, 1, temperature, myWriteAPIKey);  
 delay(30000); // ThingSpeak will only accept updates every 15 seconds.
  float humidity= h;
 ThingSpeak.writeField(myChannelNumber, 2, humidity, myWriteAPIKey);   
 WiFiClient client = server.available();
 client.println("HTTP/1.1 200 OK");
 client.println("Content-Type: text/html");
 client.println("Connection: close");  // the connection will be closed after completion of the response
 client.println("Refresh: 10");  // update the page after 10 sec
 client.println();
 client.println("<!DOCTYPE HTML>");
 client.println("<html>");
 client.print("<p style='text-align: center;'><span style='font-size: x-large;'><strong>Digital Temperature meter</strong></span></p>");
 client.print("<p style='text-align: center;'><span style='color: #0000ff;'><strong style='font-size: large;'>Temperature = ");
 client.println(t);
 client.print("<p style='text-align: center;'><span style='color: #0000ff;'><strong style='font-size: large;'>Humidity  = ");
 client.println(h);
 client.print("</p>");
 client.println("</html>");
 delay(5000);
}
void dht34()
{
  float t = dht.readTemperature();
  Serial.print("Temperature:");
  Serial.println(t);
  delay(500);
  float h = dht.readHumidity();
  Serial.print("Humidity:");
  Serial.println(h);
  delay(500);  
}
void motor()
{
  dht34();
  if(t>40)
  {
    digitalWrite(4,HIGH);
  }
  else
  {
    digitalWrite(4,LOW);
  }
}
void lcd16()
{
  dht34();
  lcd.clear();
  lcd.println(t);
  lcd.print("Temperature");
  lcd.setCursor(0,1);
  lcd.println(h);
  lcd.print("Humidity");
}
