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

