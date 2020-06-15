#include "debounce.h"
#define butpin 10
#define delaydebounce 50 //millisec
DEBOUNCE button1(butpin,delaydebounce);
void setup()
{
  Serial.begin(9600);
  button1.setup();
}

void loop() {
  if(button1.ReadState()==LOW)
  {
    Serial.printf("outside The button %d is pressed\n",butpin);
  }
}
