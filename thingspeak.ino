#include <LiquidCrystal.h>
#include <ThingSpeak.h>
#include <ETH.h>
#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiSTA.h>
#include <WiFiType.h>
#include <WiFiUdp.h>


 
const int rs = 13, en = 12, d4 = 14, d5 = 27, d6 = 26, d7 = 25;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const char* ssid     = "sravani"; 
const char* password = "sravani123";
WiFiClient client;
unsigned long myChannelNumber =787485; 
const char *myWriteAPIKey ="QD0V7PU36OCRMDDW";
float temp_celsius = 0;
float temp_fahrenheit = 0;

WiFiServer server(80);
void setup() {
  lcd.begin(16, 2);
  pinMode(4,OUTPUT);
  Serial.begin(115200);
  pinMode(34, INPUT);   
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
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
   float a = analogRead(34);
   temp_celsius =  (a/9.31) ;
   temp_fahrenheit = (temp_celsius * 1.8) + 32.0;
   Serial.print("  Temperature = ");
   Serial.print(temp_celsius);
   Serial.print(" Celsius, ");
   delay(500);
   Serial.print(temp_fahrenheit);
   Serial.println(" Fahrenheit");
   delay(2000);
    lcd.clear();
    lcd.print(temp_celsius);
    lcd.print(" Celsius, ");
    lcd.setCursor(0,1);
    lcd.print(temp_fahrenheit);
    lcd.print("Fahrenheit"); 
     if(temp_celsius>35){
    digitalWrite(4,HIGH);
   }
   else
   {
    digitalWrite(4,LOW);
    }
    WiFiClient client = server.available();
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");  
    client.println("Refresh: 10"); 
    client.println();
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.print("<p style='text-align: center;'><span style='font-size: x-large;'><strong>Digital Temperature meter</strong></span></p>");
    client.print("<p style='text-align: center;'><span style='color: #0000ff;'><strong style='font-size: large;'>Temperature (*C)= ");
    client.println(temp_celsius);
    client.print("<p style='text-align: center;'><span style='color: #0000ff;'><strong style='font-size: large;'>Temperature (F) = ");
    client.println(temp_fahrenheit);
    client.print("</p>");
    client.println("</html>");
    delay(5000);
    static boolean data_state = false;
    float temperature=temp_celsius;
    ThingSpeak.writeField(myChannelNumber, 1, temperature, myWriteAPIKey);
    delay(30000);


float temp_celsius = 0;
float temp_fahrenheit = 0;
}
