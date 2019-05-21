void setup() {
  
  Serial.begin(115200);
  pinMode(2,INPUT);   //PIR_input
  pinMode(4,OUTPUT);    // led_output

}

void loop() {
  bool x  = digitalRead(2);

  if(x==HIGH)
  {
    Serial.println("presence detected");
    digitalWrite(4,HIGH); // if presence detected led glows
  }
  else
  Serial.println("no presence");
  digitalWrite(4,LOW); //if presence not detected led doesn't glow
}
