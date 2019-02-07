#include <SoftwareSerial.h>
#include <stdlib.h>


#define DEBUG true
#define SSID "Johnpk"     // "SSID-WiFiname"
#define PASS "johnpremkumar" // "password"
#define IP "184.106.153.149"      // thingspeak.com ip

String msg = "GET /update?key=5T8Y118H9NUMHSLK"; //change it with your api key like "GET /update?key=Your Api Key"
SoftwareSerial esp8266(0,1);

int L1=4;
int l2=5;
int L3=6;
int irpin1=11;
int irpin2=12;
int irpin3=13;
int status1;
int status2;
int status3;
int error;

void setup()
{
Serial.begin(9600); //or use default 115200.
esp8266.begin(9600);
pinMode(L1,OUTPUT);
pinMode(L2,OUTPUT);
pinMode(L3,OUTPUT);
pinMode(irpin1,INPUT);
pinMode(irpin2,INPUT);
pinMode(irpin3,INPUT);
Serial.println("AT");
esp8266.println("AT");
delay(5000);
if(esp8266.find("OK"))
{
  connectWiFi();
}
}

void loop()
{
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

  void irstatus()
{
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += IP;
  cmd += "\",80";
  Serial.println(cmd);
  esp8266.println(cmd);
  delay(2000);
  if(esp8266.find("Error"))
  {
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
  Serial.print("AT+CIPSEND=");
  esp8266.print("AT+CIPSEND=");
  Serial.println(cmd.length());
  esp8266.println(cmd.length());
  if(esp8266.find(">"))
  {
    Serial.print(cmd);
    esp8266.print(cmd);
  }
  else
  {
    Serial.println("AT+CIPCLOSE");
    esp8266.println("AT+CIPCLOSE");
    
  }
}

}


boolean connectWiFi()
{
  Serial.println("AT+CWMODE=1");
  esp8266.println("AT+CWMODE=1");
  delay(2000);
  String cmd="AT+CWJAP=\"";
  cmd+=SSID;
  cmd+="\",\"";
  cmd+=PASS;
  cmd+="\"";
  Serial.println(cmd);
  esp8266.println(cmd);
  delay(5000);
  if(esp8266.find("OK"))
  {
    return true;
  }
  else
  {
    return false;
  }
}

