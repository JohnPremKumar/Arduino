#include<stdlib.h>
#include <SoftwareSerial.h>

SoftwareSerial ESP8266(2, 3); // RX, TX

void sendDebug(String cmd)
    {
      Serial.print("SEND: ");
      Serial.println(cmd);
      delay(05);
      ESP8266.println(cmd);
      
    } 

void SendData(String command,unsigned int Value)
    
     {
        String cmd;
        d:sendDebug("AT+CIPSTART=\"TCP\",\"184.106.153.149\",80");
      //  delay(512);
         
         if(ESP8266.find("OK"))
           
             {
              Serial.println("RECEIVED: OK");
            }
        else
            {
              Serial.print("RECEIVED: Error");
              goto d;
            }
  
          cmd = command;
          cmd+=Value;
          cmd+= "\r\n";
          e:ESP8266.print("AT+CIPSEND=");
          Serial.print("SEND:AT+CIPSEND=");
          ESP8266.println(cmd.length());
          Serial.println(cmd.length());
      //    delay(512);
          
          
          if(ESP8266.find(">"))
                {
                  Serial.print(">");
                  sendDebug(cmd);
                }
          else
                {
                  goto e;
                }
            delay(512);
            f:sendDebug("AT+CIPCLOSE");
           
           
           if(ESP8266.find("OK"))
                 {
                  Serial.println("RECEIVED: OK");
                }
          else
                {
                  Serial.println("RECEIVED: Error");
                  goto f;
                }
        }

unsigned char ReceiveData(String command)
{

  unsigned int d;
  String cmd;
  g:sendDebug("AT+CIPSTART=\"TCP\",\"184.106.153.149\",80");
 // delay(510);
       if(ESP8266.find("OK"))
       {
        Serial.println("RECEIVED: OK");
       }
        else
        {
          Serial.print("RECEIVED: Error");
          goto g;
        }
        
  cmd = command;
  cmd+= "\r\n";
  h:ESP8266.print("AT+CIPSEND=");
  Serial.print("SEND:AT+CIPSEND=");
  ESP8266.println(cmd.length());
  Serial.println(cmd.length());
 // delay(512);
      if(ESP8266.find(">"))
      {
        Serial.print(">");
        sendDebug(cmd);
        
        if(ESP8266.find("+IPD"))
         
         {
            Serial.print("+IPD Found");
            d=ESP8266.read();
            Serial.write(d);
            d=ESP8266.read();
            Serial.write(d);
            d=ESP8266.read();
            Serial.write(d);
            d=ESP8266.read();
            Serial.write(d);
           // Serial.println(d);
         }
    
      else
          {
            
            sendDebug("AT+CIPCLOSE");
             return d;
          }
  }
  else
  {
    goto h;
  }
  
  delay(50);

  i:sendDebug("AT+CIPCLOSE");
 
   
   if(ESP8266.find("OK"))
       {
        Serial.println("RECEIVED: OK");
       }
   else
      {
        Serial.println("RECEIVED: Error");
        goto i;
      }
  return d;

}

 
boolean connectWiFi(){

  ESP8266.begin(115200);
  Serial.begin(115200);  


  Serial.println("ESP8266 MODUE INITIALIZING.....");
  delay(50);
   
  a:sendDebug("AT");
  if(ESP8266.find("OK")){
    Serial.println("RECEIVED: OK");
  }
  else if(ESP8266.find("ERROR")){
    Serial.println("RECEIVED: Error");
    goto a;
  }
  else
  {
    Serial.println("RECEIVED: Error");
    goto a;
  }
  
  b:sendDebug("AT+CWMODE=1");
 // delay(100);

    if(ESP8266.find("OK")){
    Serial.println("RECEIVED: OK");
  }else{
    Serial.println("RECEIVED: Error");
    goto b;
  }
  
  c:sendDebug("AT+CWJAP=\"Johnpk\",\"johnpremkumar\""); //WiFi Password Change Here
 delay(100);
  
  if(ESP8266.find("OK")){
    Serial.println("RECEIVED: OK");
  }else{
    Serial.println("RECEIVED: Error");
    goto c;
  }
  Serial.println();
}
