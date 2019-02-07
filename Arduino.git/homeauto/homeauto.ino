
#include "iot.h"


String RECEIVE = "GET /channels/338785/fields/1/last"; // change channal ID

void setup()
{
  connectWiFi();
  pinMode(7, OUTPUT);

}

void loop() {
  unsigned int a;

  delay(200);
  a = ReceiveData(RECEIVE);

  if (a == '1')
  {
    digitalWrite(7, HIGH);
  }
  else if (a == '0')
  {
    digitalWrite(7, LOW);
  }
}


