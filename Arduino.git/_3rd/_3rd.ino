#include "Timer.h"
#include <SoftwareSerial.h>
#define SSID "Johnpk"
#define PASS "johnpremkumar"
#define IP "184.106.153.149" 
String msg = "GET /update?key=5T8Y118H9NUMHSLK";


SoftwareSerial ESP8266T(2,3);

void sendDebug(String cmd){
  Serial.print("SEND: ");
  Serial.println(cmd);
  ESP8266T.println(cmd);
} 

boolean connectWiFi(){

  
Serial.begin(9600);
ESP8266T.begin(115200);

  ESP8266T.println("AT+CWMODE=1");
  delay(2000);
  String cmd="AT+CWJAP=\"";
  cmd+=SSID;
  cmd+="\",\"";
  cmd+=PASS;
  cmd+="\"";
  sendDebug(cmd);
  delay(5000);
  if(ESP8266T.find("OK")){
    Serial.println("RECEIVED: OK");
    return true;
  }else{
    Serial.println("RECEIVED: Error");
    return false;
  }
}

void Acessifttt(){
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += IP;
  cmd += "\",80";
  sendDebug(cmd);
  delay(2000);
  if(ESP8266T.find("Error")){
    Serial.print("RECEIVED: Error");
    return;
  }
  cmd = msg ;
  cmd += "&field1=";    //field 1 for temperature
  cmd += status1 ;
  cmd += "&field2=";  //field 2 for humidity
  cmd += status2;
  cmd += "&field3=";
  cmd += status3;
  cmd += "\r\n";
  ESP8266T.print("AT+CIPSEND=");
  ESP8266T.println(cmd.length());
  delay(2000);
  if(ESP8266T.find(">")){
    Serial.print(">");
    Serial.print(cmd);
    ESP8266T.print(cmd);
  }else{
    sendDebug("AT+CIPCLOSE");
  }
  if(ESP8266T.find("OK")){
    Serial.println("RECEIVED: OK");
  }else{
    Serial.println("RECEIVED: Error");
  }
}


Timer t;

int L1=4;
int l2=5;
int L3=6;
int irpin1=11;
int irpin2=12;
int irpin3=13;
int status1;
int status2;
int status3;void setup() {
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
   // put your main code here, to run repeatedly:
  int a;
  t.update();

  int ir1status=digitalRead(irpin1);
  int ir2status=digitalRead(irpin2);
  int ir3status=digitalRead(irpin3);
  if(ir1status==HIGH)
  {
    digitalWrite(L1,HIGH);
    status1=1;
    delay(1000);
  }
  else
  {
    digitalWrite(L1,LOW);
    status1=0;
    delay(1000);
  }
if(ir2status==HIGH)
  {
    digitalWrite(L2,HIGH);
    status2=1;
    delay(1000);
  }
  else
  {
    digitalWrite(L1,LOW);
    status2=0;
    delay(1000);
  }
if(ir3status==HIGH)
  {
    digitalWrite(L3,HIGH);
    status3=1;
    delay(1000);
  }
  else
  {
    digitalWrite(L1,LOW);
    status3=0;
    delay(1000);
  }

}

