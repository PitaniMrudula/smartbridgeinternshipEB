void setup()
{
  Serial.begin(115200);
  pinMode(2,OUTPUT);
  // put your setup code here, to run once:

}

void loop() 
{
  Serial.println("Low");
  digitalWrite(2,LOW);
  delay(100);
  Serial.println("High");
  digitalWrite(2,HIGH);
  delay(100);
  
  // put your main code here, to run repeatedly:

}
