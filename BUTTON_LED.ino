

void setup() 
{
pinMode(2,INPUT);
pinMode(4,OUTPUT);
}

void loop() {
 int x= digitalRead(2);

  if( x == HIGH)
  {
    digitalWrite(4,LOW);
    
  }
  else
  digitalWrite(4,HIGH);
  
  // put your main code here, to run repeatedly:

}
