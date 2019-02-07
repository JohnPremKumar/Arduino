#include <SoftwareSerial.h>

#define SSID "Johnpk"
#define PASS "johnpremkumar"
#define IP "translate.ubidots.com" 
String select_button = "multi|LV|A1E-j9xJOkEJfyYXplW1Fz2i2DZRFMKh5H|multiauto:buttoncontrol|end";
String select_voice = "multi|LV|A1E-j9xJOkEJfyYXplW1Fz2i2DZRFMKh5H|multiauto:voicecontrol|end";
String select_motion = "multi|LV|A1E-j9xJOkEJfyYXplW1Fz2i2DZRFMKh5H|multiauto:motioncontrol|end";
String select_fan = "multi|LV|A1E-j9xJOkEJfyYXplW1Fz2i2DZRFMKh5H|multiauto:fan|end";
String select_light = "multi|LV|A1E-j9xJOkEJfyYXplW1Fz2i2DZRFMKh5H|multiauto:light|end";


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
String button;
String voice;
String motion;
String fan_control;
String light_control;
int motion_status;
int a,b,c,d,e;


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


void getdata()
{
  x2:String cmd1 = "AT+CIPSTART=\"TCP\",\"";
  cmd1 += IP;
  cmd1 += "\",9012";
  sendDebug(cmd1);
  delay(100);
  if(ESP8266T.find("Error")){
    Serial.print("RECEIVED: Error");
    goto x2;
  }
  cmd1 = select_button;
  cmd1 += "\r\n";
  ESP8266T.print("AT+CIPSEND=");
  ESP8266T.println(cmd1.length());
  delay(100);
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
     button=ESP8266T.read();
     Serial.print(button);
  }
  }else{
    goto x2;
  }

  x3:String cmd2 = "AT+CIPSTART=\"TCP\",\"";
  cmd2 += IP;
  cmd2 += "\",9012";
  sendDebug(cmd2);
  delay(100);
  if(ESP8266T.find("Error")){
    Serial.print("RECEIVED: Error");
    goto x3;
  }
  cmd2 = select_voice;
  cmd2 += "\r\n";
  ESP8266T.print("AT+CIPSEND=");
  ESP8266T.println(cmd2.length());
  delay(100);
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
     voice=ESP8266T.read();
     Serial.print(voice);
  }
  }else{
    goto x3;
  }

  x4:String cmd3 = "AT+CIPSTART=\"TCP\",\"";
  cmd3 += IP;
  cmd3 += "\",9012";
  sendDebug(cmd3);
  delay(100);
  if(ESP8266T.find("Error")){
    Serial.print("RECEIVED: Error");
    goto x4;
  }
  cmd3 = select_motion;
  cmd3 += "\r\n";
  ESP8266T.print("AT+CIPSEND=");
  ESP8266T.println(cmd3.length());
  delay(100);
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
     Serial.print(motion);
  }
  }else{
    goto x4;
  }


  x5:String cmd4 = "AT+CIPSTART=\"TCP\",\"";
  cmd4 += IP;
  cmd4 += "\",9012";
  sendDebug(cmd4);
  delay(100);
  if(ESP8266T.find("Error")){
    Serial.print("RECEIVED: Error");
    goto x5;
  }
  cmd4 = select_fan;
  cmd4 += "\r\n";
  ESP8266T.print("AT+CIPSEND=");
  ESP8266T.println(cmd4.length());
  delay(100);
  if(ESP8266T.find(">")){
    Serial.print(">");
    Serial.print(cmd4);
    ESP8266T.print(cmd4);

    if(ESP8266T.find("+IPD"))
         
    {
     Serial.print("+IPD Found");
     d=ESP8266T.read();
     Serial.write(d);
     d=ESP8266T.read();
     Serial.write(d);
     d=ESP8266T.read();
     Serial.write(d);
     d=ESP8266T.read();
     Serial.print(d);
  }
  }else{
    goto x5;
  }

  x6:String cmd5 = "AT+CIPSTART=\"TCP\",\"";
  cmd5 += IP;
  cmd5 += "\",9012";
  sendDebug(cmd5);
  delay(100);
  if(ESP8266T.find("Error")){
    Serial.print("RECEIVED: Error");
    goto x6;
  }
  cmd5 = select_light;
  cmd5 += "\r\n";
  ESP8266T.print("AT+CIPSEND=");
  ESP8266T.println(cmd5.length());
  delay(100);
  if(ESP8266T.find(">")){
    Serial.print(">");
    Serial.print(cmd5);
    ESP8266T.print(cmd5);

    if(ESP8266T.find("+IPD"))
         
    {
     Serial.print("+IPD Found");
     e=ESP8266T.read();
     Serial.write(e);
     e=ESP8266T.read();
     Serial.write(e);
     e=ESP8266T.read();
     Serial.write(e);
     light_control=ESP8266T.read();
     Serial.print(light_control);
  }
  }else{
    goto x6;
  }
}

  
