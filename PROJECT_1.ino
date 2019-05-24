  #include <LiquidCrystal.h>
#include <WiFi.h>
const int rs = 22, en = 23, d4 = 5, d5 = 18, d6 = 19, d7 = 21;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const char* ssid     = "sravani"; // Your ssid
const char* password = "sravani123"; // Your Password

float temp_celsius = 0;
float temp_fahrenheit = 0;

WiFiServer server(80);

void setup() 
{
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
}
void loop() {
  lm35();
  lcd16();
  relay();
}

void lm35()
{
  float a = analogRead(34);
temp_celsius =  (a/9.31) ;  // To convert analog values to Celsius We have 3.3 V on our board and we know that output voltage of LM35 varies by 10 mV to every degree Celsius rise/fall. So , (A0*3300/10)/1023 = celsius
temp_fahrenheit = temp_celsius * 1.8 + 32.0;

Serial.print("  Temperature = ");
Serial.print(temp_celsius);
Serial.print(" Celsius, ");
Serial.print(temp_fahrenheit);
Serial.println(" Fahrenheit");
}
  void relay()
  {
    lm35();
    if (temp_celsius_40)
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
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      lcd.write(Serial.read());
    }
  }}
