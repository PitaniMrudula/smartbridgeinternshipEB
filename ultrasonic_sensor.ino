const int trigPin=4;
const int echoPin =5;
long duration;
int distance;

void setup() 
{
 pinMode(2,OUTPUT);
 pinMode(19,OUTPUT);
 pinMode(18,OUTPUT);

 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
 Serial.begin(115200);

}

void loop() 
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  
  
  //Calculating the distance
  distance = (duration*0.034)/2;
  Serial.print("Distance:");
  Serial.println(distance);
 
  /* using led's
  if(distance <= 1000)
  {
    digitalWrite(2,HIGH);
     digitalWrite(19,LOW);
      digitalWrite(18,LOW);
    
  }
  else if(distance>1000 || distance<2000)
        { c
        digitalWrite(19,HIGH);
        digitalWrite(2,LOW);
         digitalWrite(18,LOW);
        
       }

       else
       digitalWrite(18 ,HIGH);
         digitalWrite(19,LOW);
          digitalWrite(2,LOW);   */
}
