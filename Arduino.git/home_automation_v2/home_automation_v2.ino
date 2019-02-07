#include <SoftwareSerial.h>
#include <ArduinoJson.h>

#define SSID "Johnpk"
#define PASS "johnpremkumar"
#define IP "184.106.153.149" 
String select_button = "GET /channels/442237/feeds/last";
String select_voice = "GET /channels/442237/field/2/last";
String select_motion = "GET /channels/442237/field/3/last";
String select_fan = "GET /channels/442241/field/1/last";
String select_light = "GET /channels/442241/field/2/last";



int fan1=4;
int fan2=5;
int light=6;
int motion_sensor=8;
unsigned int button;
unsigned int voice;
unsigned int motion;
unsigned int fan_control;
unsigned int light_control;
int motion_status,i;
char select;


StaticJsonBuffer<300> jsonBuffer;
SoftwareSerial ESP8266T(2,3);



void sendDebug(String cmd){
  Serial.print("SEND: ");
  Serial.println(cmd);
  ESP8266T.println(cmd);
} 


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
  cmd1 += "\",80";
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
     button=ESP8266T.read();
     Serial.write(button);
     button=ESP8266T.read();
     Serial.write(button);
     button=ESP8266T.read();
     Serial.write(button);
     button=ESP8266T.read();
     Serial.write(button);
     button=ESP8266T.read();
     Serial.write(button);
     for(i=0;i<162;i++)
     {
     
     select=ESP8266T.read();
     Serial.print(select);
     delay(10);
     }

    // JsonObject& root = jsonBuffer.parseObject(select);
     //delay(5000);
   //  if (!root.success()) {
   // Serial.println("parseObject() failed");
   /// return;
//  }

    //button = root["field1"];
  //voice = root["field2"];
  //motion = root["field3"];
  }
  }else{
    goto x2;
  }
     
}
