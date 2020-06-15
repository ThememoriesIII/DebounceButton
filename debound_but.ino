#include "debounce.h"
DEBOUNCE button1(10,50);
void setup()
{
  Serial.begin(9600);
  button1.setup();
}

void loop() {
  if(button1.ReadState()==LOW)
    Serial.printf("The button %d is pressed\n",BUTTON_PIN); 
}
