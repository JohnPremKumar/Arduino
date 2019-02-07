int L1=4;
int L2=5;
int L3=6;
int irpin1=11;
int irpin2=12;
int irpin3=13;
int status1;
int status2;
int status3;
#include "Timer.h"
#include "thing.h"
Timer t;



void setup() {
  // put your setup code here, to run once:


pinMode(L1,OUTPUT);
pinMode(L2,OUTPUT);
pinMode(L3,OUTPUT);
pinMode(irpin1,INPUT);
pinMode(irpin2,INPUT);
pinMode(irpin3,INPUT);

connectWiFi();


int internet=t.every(1000,updateValue);

delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a;
  t.update();

  int ir1status=digitalRead(irpin1);
  int ir2status=digitalRead(irpin2);
  int ir3status=digitalRead(irpin3);
  if(ir1status==HIGH)
  {
    digitalWrite(L1,HIGH);
    status1=0;
    
  }
  else
  {
    digitalWrite(L1,LOW);
    status1=1;
    
  }
if(ir2status==HIGH)
  {
    digitalWrite(L2,HIGH);
    status2=0;
    
  }
  else
  {
    digitalWrite(L1,LOW);
    status2=1;
    
  }
if(ir3status==HIGH)
  {
    digitalWrite(L3,HIGH);
    status3=0;
    
  }
  else
  {
    digitalWrite(L1,LOW);
    status3=1;
    
  }
}
void updateValue()
{
  Acessifttt();
}
