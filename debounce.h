#ifndef DEBOUNCE_H
#define DEBOUNCE_H
// soft and simple debounce by kan
// support arduino platform and press active low only
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class DEBOUNCE
{
  private:
  int BUTTON_PIN=0;      
  int DEBOUNCE_DELAY = 50;
  int buton_SteadyState = HIGH;
  int button_laststate = HIGH;
  int button_currentState;            
  unsigned long lastDebounceTime = 0; 

  public:
  DEBOUNCE(int pin,int time_debounce=0)
  {
    DEBOUNCE_DELAY = time_debounce;
    BUTTON_PIN = pin;
  }
  void setup()
  {
    pinMode(BUTTON_PIN,INPUT_PULLUP);
  }
  boolean ReadState()
  {
    button_currentState = digitalRead(BUTTON_PIN);
    if (button_currentState != button_laststate) 
    {
      lastDebounceTime = millis();
      button_laststate = button_currentState;
    }
    if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) 
    {
      if(buton_SteadyState == HIGH && button_currentState == LOW)
      {
        Serial.printf("The button %d is pressed\n",BUTTON_PIN);   
      }
      buton_SteadyState = button_currentState;
      return buton_SteadyState;
    }
  }
};
#endif
