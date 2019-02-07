
int in1=4;
int in2=5;
void setup() {
  // put your setup code here, to run once:
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
}
