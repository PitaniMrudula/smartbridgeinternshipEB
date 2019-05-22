#include <Servo.h>
Servo myservo;
int pos=0;
const int trigPin=4;
const int echoPin =5;
long duration;
int distance;

void setup() 
{
Serial.begin(115200); 
 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
 myservo.attach(13);
 

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
 
     if(distance<=200)
     {
       for(pos=0;pos<=180;pos+=1)
       myservo.write(pos);
    
    if(pos == 90)
       delay(200);
       delay(15);
     }
   else
   for(pos=180;pos<=0;pos-=1)
   {
    myservo.write(pos);
    if(pos=90)
    delay(200);
    delay(15);
   }
       }
     
     
