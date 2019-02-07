#include <SoftwareSerial.h>

#define SSID "Johnpk"
#define PASS "johnpremkumar"
#define IP "184.106.153.149" 
String msg = "GET /update?key=5T8Y118H9NUMHSLK";
String RECEIVE1 = "GET /channels/338785/field/1/last";
String RECEIVE2 = "GET /channels/338785/field/2/last";
String RECEIVE3 = "GET /channels/338785/field/3/last";



SoftwareSerial ESP8266T(2,3);

void sendDebug(String cmd){
  Serial.print("SEND: ");
  Serial.println(cmd);
  ESP8266T.println(cmd);
} 

int L1=4;
int L2=5;
int L3=6;
int irpin1=11;
int irpin2=12;
int irpin3=13;

int ir1status;
int ir2status;
int ir3status;

void setup() {
// put your setup code here, to run once:
pinMode(L1,OUTPUT);
pinMode(L2,OUTPUT);
pinMode(L3,OUTPUT);
pinMode(irpin1,INPUT);
pinMode(irpin2,INPUT);
pinMode(irpin3,INPUT);

connectWiFi();
delay(100);

}


void loop() {
  // put your main code here, to run repeatedly:
  ir1status=digitalRead(irpin1);
  ir2status=digitalRead(irpin2);
  ir3status=digitalRead(irpin3);
  thingspeak();
  delay(1000);
  getdata();
  delay(1000);

}


boolean connectWiFi(){

  
Serial.begin(9600);
ESP8266T.begin(115200);

  ESP8266T.println("AT+CWMODE=1");
  delay(2000);
 x1:String cmd="AT+CWJAP=\"";
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
    goto x1;
  }
}

void thingspeak(){
  x2:String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += IP;
  cmd += "\",80";
  sendDebug(cmd);
  delay(200);
  if(ESP8266T.find("Error")){
    Serial.print("RECEIVED: Error");
    goto x2;
  }
  cmd = msg ;
  cmd += "&field1=";   
  cmd += ir1status;
  cmd += "&field2="; 
  cmd += ir2status;
  cmd += "&field3=";
  cmd += ir3status;
  cmd += "\r\n";
  ESP8266T.print("AT+CIPSEND=");
  ESP8266T.println(cmd.length());
  delay(200);
  if(ESP8266T.find(">")){
    Serial.print(">");
    Serial.print(cmd);
    ESP8266T.print(cmd);
  }else{
    
    goto x2;
    
  }
  if(ESP8266T.find("OK")){
    Serial.println("RECEIVED: OK");
  }else{
    Serial.println("RECEIVED: Error");
    goto x2;
  }
}




void getdata()
{
  unsigned int a;
  unsigned int b;
  unsigned int c;

 x7:String cmd1 = "AT+CIPSTART=\"TCP\",\"";
  cmd1 += IP;
  cmd1 += "\",80";
  sendDebug(cmd1);
  delay(200);
  if(ESP8266T.find("Error")){
    Serial.print("RECEIVED: Error");
    goto x7;
  }
  
  cmd1 = RECEIVE1;
  cmd1 += "\r\n";
  ESP8266T.print("AT+CIPSEND=");
  ESP8266T.println(cmd1.length());
  delay(200);
  if(ESP8266T.find(">")){
    Serial.print(">");
    Serial.print(cmd1);
    ESP8266T.print(cmd1);

    if(ESP8266T.find("+IPD"))
         
    {
     Serial.print("+IPD Found");
     a=ESP8266T.read();
     Serial.write(a);
     a=ESP8266T.read();
     Serial.write(a);
     a=ESP8266T.read();
     Serial.write(a);
     a=ESP8266T.read();
     Serial.write(a);
  }
  }else{
    
    goto x7;
  }
  if (a == '1')
  {
    digitalWrite(L1,HIGH);
    
  }  
  else if (a == '0')
  {
    digitalWrite(L1,LOW);
  }


 x8:String cmd2 = "AT+CIPSTART=\"TCP\",\"";
  cmd2 += IP;
  cmd2 += "\",80";
  sendDebug(cmd2);
  delay(200);
  if(ESP8266T.find("Error")){
    Serial.print("RECEIVED: Error");
    goto x8;
  }
 cmd2 = RECEIVE2;
  cmd2 += "\r\n";
  ESP8266T.print("AT+CIPSEND=");
  ESP8266T.println(cmd2.length());
  delay(200);
  if(ESP8266T.find(">")){
    Serial.print(">");
    Serial.print(cmd2);
    ESP8266T.print(cmd2);

    if(ESP8266T.find("+IPD"))
         
    {
     Serial.print("+IPD Found");
     b=ESP8266T.read();
     Serial.write(b);
     b=ESP8266T.read();
     Serial.write(b);
     b=ESP8266T.read();
     Serial.write(b);
     b=ESP8266T.read();
     Serial.write(b);
  }
  }else{
    goto x8;
  }
  if (b == '1')
  {
    digitalWrite(L2,HIGH);
    
  }  
  else if (b == '0')
  {
    digitalWrite(L2,LOW);
  }


 x9:String cmd3 = "AT+CIPSTART=\"TCP\",\"";
  cmd3 += IP;
  cmd3 += "\",80";
  sendDebug(cmd3);
  delay(200);
  if(ESP8266T.find("Error")){
    Serial.print("RECEIVED: Error");
    goto x9;
  }
 cmd3 = RECEIVE3;
  cmd3 += "\r\n";
  ESP8266T.print("AT+CIPSEND=");
  ESP8266T.println(cmd3.length());
  delay(200);
  if(ESP8266T.find(">")){
    Serial.print(">");
    Serial.print(cmd3);
    ESP8266T.print(cmd3);

    if(ESP8266T.find("+IPD"))
         
    {
     Serial.print("+IPD Found");
     c=ESP8266T.read();
     Serial.write(c);
     c=ESP8266T.read();
     Serial.write(c);
     c=ESP8266T.read();
     Serial.write(c);
     c=ESP8266T.read();
     Serial.write(c);
  }
  }else{
    goto x9;
  }
  if (c == '1')
  {
    digitalWrite(L3,HIGH);
   
  }  
  else if (c == '0')
  {
    digitalWrite(L3,LOW);
  }
  
}

