#include <Servo.h>
#include <SoftwareSerial.h>


#define pinBase 12 
#define pinDerecho 11 
#define pinIzquierdo 10 
#define pinGarra 9 

Servo motorBase;
Servo motorDerecho;
Servo motorIzquierdo;
Servo motorGarra;
SoftwareSerial BT(2,3);

void setup() 

{

motorBase.attach(pinBase); 
motorDerecho.attach(pinDerecho); 
motorIzquierdo.attach(pinIzquierdo); 
motorGarra.attach(pinGarra);  
BT.begin(9600); 
Serial.begin(9600); //Establecer baudios

}

int j,k,l;

char s[6];

void loop() 

{
if (BT.available()>0 && BT.available()<=6)
{
  BT.readBytes(s,6);
  BT.println(s);
  
  switch(s[0])
  
  {
    case'b':
    j=(s[1]-48)*100;
    k=(s[2]-48)*10;
    l=j+k+(s[3]-48);
    
    motorBase.write(l);
    BT.println(l);
    break;
    
    case'd':
    j=(s[1]-48)*100;
    k=(s[2]-48)*10;
    l=j+k+(s[3]-48);

    motorDerecho.write(l);
    BT.println(l);
    break;
    
    case'i':
    j=(s[1]-48)*100;
    k=(s[2]-48)*10;
    l=j+k+(s[3]-48);

    motorIzquierdo.write(l);
    BT.println(l);
    break;

    case'g':
    j=(s[1]-48)*100;
    k=(s[2]-48)*10;
    l=j+k+(s[3]-48);

    motorGarra.write(l);
    BT.println(l);
    break;
    
  }
  if (Serial.available()>0 && Serial.available()<=6)
 {
  Serial.readBytes(s,6);
  Serial.println(s);

  switch(s[0])
  
  {
    case'b':
    j=(s[1]-48)*100;
    k=(s[2]-48)*10;
    l=j+k+(s[3]-48);
    
    motorBase.write(l);
    Serial.println(l);
    break;
    
    case'd':
    j=(s[1]-48)*100;
    k=(s[2]-48)*10;
    l=j+k+(s[3]-48);

    motorDerecho.write(l);
    Serial.println(l);
    break;
    
    case'i':
    j=(s[1]-48)*100;
    k=(s[2]-48)*10;
    l=j+k+(s[3]-48);

    motorIzquierdo.write(l);
    Serial.println(l);
    break;

    case'g':
    j=(s[1]-48)*100;
    k=(s[2]-48)*10;
    l=j+k+(s[3]-48);

    motorGarra.write(l);
    Serial.println(l);
    break;
  }
 }
}
}
