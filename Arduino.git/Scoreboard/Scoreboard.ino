
#include <SoftwareSerial.h>

#define SSID " "
#define PASS " " //on your wifi which u have mentioned here 
#define IP "184.106.153.149" 
String msg = "GET /update?key=HFHVE9VOZXYXM71X";

SoftwareSerial ESP8266T(2,3);

void sendDebug(String cmd){
  Serial.print("SEND: ");
  Serial.println(cmd);
  ESP8266T.println(cmd);
} 
int switch1=14;
int switch2=15;
int switch3=16;
int switch4=17;
int switchstate1=0;
int switchstate2=0;
int switchstate3=0;
int switchstate4=0;
int basketballscore=0;
int footballscore=0;
int volleyballscore=0;
void setup() {
  // put your setup code here, to run once:
 
  pinMode(switch1,INPUT_PULLUP);
  pinMode(switch2,INPUT_PULLUP);
  pinMode(switch3,INPUT_PULLUP);
  pinMode(switch4,INPUT_PULLUP); 
  connectWiFi();
delay(100);
Serial.println("Basket ball");
Serial.println("Foot ball");
Serial.println("volley ball");

}

void loop() {
  // put your main code here, to run repeatedly:
  switchstate1=digitalRead(switch1);
  switchstate2=digitalRead(switch2);
  switchstate3=digitalRead(switch3);
  switchstate4=digitalRead(switch4);

   if (switchstate1==HIGH) {
      basketballscore=basketballscore+1;
      Serial.println("Basketball score=");
      Serial.println(basketballscore);
       delay(500);
     
    }
     if (switchstate2==HIGH) {
      footballscore=footballscore+1;
      Serial.println("Football score=");
      Serial.println(footballscore);
      delay(500);
     
    }
     if (switchstate3==HIGH) {
      volleyballscore=volleyballscore+1;
      Serial.println("Volleyball score=");
      Serial.println(volleyballscore);
       delay(500);
     
    }
     if (switchstate4==HIGH) {
      basketballscore=volleyballscore=footballscore=0;
      Serial.println("All Scores reset");
       delay(500);
     
    }
    thingspeak();
  delay(10000);
    

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

void thingspeak(){
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += IP;
  cmd += "\",80";
  sendDebug(cmd);
  delay(2000);
  if(ESP8266T.find("Error")){
    Serial.print("RECEIVED: Error");
    return;
  }
  if(switchstate4==LOW)
  {
     cmd = msg ;
  cmd += "&field1=";    //field 1 for temperature
  cmd += basketballscore;
  cmd += "&field2=";  //field 2 for humidity
  cmd += footballscore;
  cmd += "&field3=";
  cmd += volleyballscore;
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
  
  else{
     cmd = msg ;
  cmd += "&field1=";    //field 1 for temperature
  cmd += 0;
  cmd += "&field2=";  //field 2 for humidity
  cmd += 0;
  cmd += "&field3=";
  cmd += 0;
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
    
  
}
