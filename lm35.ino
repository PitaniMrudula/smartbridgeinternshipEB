void setup()
{
  Serial.begin(115200);
  pinMode(34,INPUT);
}

void loop() 
{
  int a = analogRead(34);

  Serial.println(a);

}
