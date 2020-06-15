#include "debounce.h"
DEBOUNCE button1(10,50);
void setup()
{
  Serial.begin(9600);
  button1.setup();
}

void loop() {
  button1.ReadState();
}
