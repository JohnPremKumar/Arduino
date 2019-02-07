#include <SoftwareSerial.h>
int motion_sensor=8;
int motion_status;
void setup() {
  // put your setup code here, to run once:
  
  pinMode(motion_sensor,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  motion_status = digitalRead(motion_sensor);
  Serial.println(motion_status);
  delay(1000);
  
}
