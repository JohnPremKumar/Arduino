#include <SoftwareSerial.h>

#define SSID "Johnpk"
#define PASS "johnpremkumar"
#define IP "184.106.153.149" 
String select_button = "GET /channels/442237/field/1/last";
String select_voice = "GET /channels/442237/field/2/last";
String select_motion = "GET /channels/442237/field/3/last";
String select_fan = "GET /channels/442241/field/1/last";
String select_light = "GET /channels/442241/field/2/last";


SoftwareSerial ESP8266T(2,3);

void sendDebug(String cmd){
  Serial.print("SEND: ");
  Serial.println(cmd);
  ESP8266T.println(cmd);
} 
int fan1=4;
int fan2=5;
int light=6;
int motion_sensor=8;
unsigned int button;
unsigned int voice;
unsigned int motion;
unsigned int fan_control;
unsigned int light_control;
int motion_status;


void setup() {

  pinMode(fan1,OUTPUT);
  pinMode(fan2,OUTPUT);
  pinMode(light,OUTPUT);
  pinMode(motion_sensor,INPUT);
  connectWiFi();
  delay(100);
  

}

void loop() {

  motion_status = digitalRead(motion_sensor);
  delay(200);
  getdata();
 

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


void getdata()
{
  x2:String cmd1 = "AT+CIPSTART=\"TCP\",\"";
  cmd1 += IP;
  cmd1 += "\",80";
  sendDebug(cmd1);
  if(ESP8266T.find("Error")){
    Serial.print("RECEIVED: Error");
    goto x2;
  }
  goto a1;
  a1:cmd1 = select_button;
  cmd1 += "\r\n";
  ESP8266T.print("AT+CIPSEND=");
  ESP8266T.println(cmd1.length());
  if(ESP8266T.find(">")){
    Serial.print(">");
    Serial.print(cmd1);
    ESP8266T.print(cmd1);

    if(ESP8266T.find("+IPD"))
         
    {
     Serial.print("+IPD Found");
     button=ESP8266T.read();
     Serial.write(button);
     button=ESP8266T.read();
     Serial.write(button);
     button=ESP8266T.read();
     Serial.write(button);
     button=ESP8266T.read();
     Serial.write(button);
  }
  }else{
    goto a1;
  }

  x3:String cmd2 = "AT+CIPSTART=\"TCP\",\"";
  cmd2 += IP;
  cmd2 += "\",80";
  sendDebug(cmd2);
  if(ESP8266T.find("Error")){
    Serial.print("RECEIVED: Error");
    goto x3;
  }
  goto a2;
  a2:cmd2 = select_voice;
  cmd2 += "\r\n";
  ESP8266T.print("AT+CIPSEND=");
  ESP8266T.println(cmd2.length());
  if(ESP8266T.find(">")){
    Serial.print(">");
    Serial.print(cmd2);
    ESP8266T.print(cmd2);

    if(ESP8266T.find("+IPD"))
         
    {
     Serial.print("+IPD Found");
     voice=ESP8266T.read();
     Serial.write(voice);
     voice=ESP8266T.read();
     Serial.write(voice);
     voice=ESP8266T.read();
     Serial.write(voice);
     voice=ESP8266T.read();
     Serial.write(voice);
  }
  }else{
    goto a2;
  }

  x4:String cmd3 = "AT+CIPSTART=\"TCP\",\"";
  cmd3 += IP;
  cmd3 += "\",80";
  sendDebug(cmd3);

  if(ESP8266T.find("Error")){
    Serial.print("RECEIVED: Error");
    goto x4;
  }goto a3;
  a3:cmd3 = select_motion;
  cmd3 += "\r\n";
  ESP8266T.print("AT+CIPSEND=");
  ESP8266T.println(cmd3.length());
  if(ESP8266T.find(">")){
    Serial.print(">");
    Serial.print(cmd3);
    ESP8266T.print(cmd3);

    if(ESP8266T.find("+IPD"))
         
    {
     Serial.print("+IPD Found");
     motion=ESP8266T.read();
     Serial.write(motion);
     motion=ESP8266T.read();
     Serial.write(motion);
     motion=ESP8266T.read();
     Serial.write(motion);
     motion=ESP8266T.read();
     Serial.write(motion);
  }
  }else{
    goto a3;
  }


  x5:String cmd4 = "AT+CIPSTART=\"TCP\",\"";
  cmd4 += IP;
  cmd4 += "\",80";
  sendDebug(cmd4);

  if(ESP8266T.find("Error")){
    Serial.print("RECEIVED: Error");
    goto x5;
  }
  goto a4;
  a4:cmd4 = select_fan;
  cmd4 += "\r\n";
  ESP8266T.print("AT+CIPSEND=");
  ESP8266T.println(cmd4.length());
  if(ESP8266T.find(">")){
    Serial.print(">");
    Serial.print(cmd4);
    ESP8266T.print(cmd4);

    if(ESP8266T.find("+IPD"))
         
    {
     Serial.print("+IPD Found");
     fan_control=ESP8266T.read();
     Serial.write(fan_control);
     fan_control=ESP8266T.read();
     Serial.write(fan_control);
     fan_control=ESP8266T.read();
     Serial.write(fan_control);
     fan_control=ESP8266T.read();
     Serial.write(fan_control);
  }
  }else{
    goto a4;
  }

  x6:String cmd5 = "AT+CIPSTART=\"TCP\",\"";
  cmd5 += IP;
  cmd5 += "\",80";
  sendDebug(cmd5);

  if(ESP8266T.find("Error")){
    Serial.print("RECEIVED: Error");
    goto x6;
  }
  goto a5;
  a5:cmd5 = select_light;
  cmd5 += "\r\n";
  ESP8266T.print("AT+CIPSEND=");
  ESP8266T.println(cmd5.length());
  if(ESP8266T.find(">")){
    Serial.print(">");
    Serial.print(cmd5);
    ESP8266T.print(cmd5);

    if(ESP8266T.find("+IPD"))
         
    {
     Serial.print("+IPD Found");
     light_control=ESP8266T.read();
     Serial.write(light_control);
     light_control=ESP8266T.read();
     Serial.write(light_control);
     light_control=ESP8266T.read();
     Serial.write(light_control);
     light_control=ESP8266T.read();
     Serial.write(light_control);
  }
  }else{
    goto a5;
  }

 if( button == '1' and fan_control == '1')
  {
   digitalWrite(fan1,HIGH);
   
   voice=0;
   motion=0; 
  }
  else if( fan_control == '0')
  {
   digitalWrite(fan1,LOW);
  
  }
  if( button == '1' and light_control == '1')
  {
   digitalWrite(fan2,HIGH);
   voice=0;
   motion=0; 
  }
  else if( light_control == '0')
  {
   digitalWrite(fan2,LOW);  
  }

  

  if( voice == '1' and fan_control == '1')
  {
   digitalWrite(fan1,HIGH);
   button=0;
   motion=0; 
  }
  else if( fan_control == '0')
  {
   digitalWrite(fan1,LOW);
     
  }
  if( voice == '1' and light_control == '1')
  {
   digitalWrite(light,HIGH);
   button=0;
   motion=0; 
  }
  else if( light_control == '0')
  {
   digitalWrite(light,LOW);  
  }
  



  if( motion == '1' && motion_status == 1)
  {
   button=0;
   voice=0; 
   digitalWrite(fan1,HIGH);

   digitalWrite(light,HIGH);
  }
  else if( motion_status == '0')
  {
   digitalWrite(light,LOW);
   digitalWrite(fan1,LOW);
  
  }
    
}



