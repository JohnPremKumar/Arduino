
int ldr = A0;
int ldrstatus;
int relaypin = 3; //change the pin number according to your circuit

void setup() {
  // put your setup code here, to run once:
  pinMode(ldr,INPUT);
  pinMode(relay,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  ldrstatus = analogRead(ldr);
  delay(100);
  if(ldrstatus <=300)  //change value as you need ldr value range 0-1023
  {
  digitalWrite(relaypin,LOW); //turns relay on
    
  }
  else
  {
  digitalWrite(relaypin,HIGH); //turns off relay  
  }
  

}
