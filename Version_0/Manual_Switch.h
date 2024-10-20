#ifndef _MANUAL_SWITCH_H
#define _MANUAL_SWITCH_H

#include <AceButton.h>    // https://github.com/bxparks/AceButton (1.9.2)
#include "Relay.h"

// for Turning On and Off the Serial Monitor
#define DEBUG_SWITCH 1

using namespace ace_button;

// GPIO for switch //
static uint8_t switch1 = 26;
static uint8_t switch2 = 27;
static uint8_t switch3 = 32;
static uint8_t switch4 = 33;
static uint8_t switch5 = 34;
static uint8_t switch6 = 35;
static uint8_t switch7 = 36;

ButtonConfig config1;
AceButton button1(&config1);
ButtonConfig config2;
AceButton button2(&config2);
ButtonConfig config3;
AceButton button3(&config3);
ButtonConfig config4;
AceButton button4(&config4);
ButtonConfig config5;
AceButton button5(&config5);
ButtonConfig config6;
AceButton button6(&config6);
ButtonConfig config7;
AceButton button7(&config7);

void handleEvent1(AceButton*, uint8_t, uint8_t);
void handleEvent2(AceButton*, uint8_t, uint8_t);
void handleEvent3(AceButton*, uint8_t, uint8_t);
void handleEvent4(AceButton*, uint8_t, uint8_t);
void handleEvent5(AceButton*, uint8_t, uint8_t);
void handleEvent6(AceButton*, uint8_t, uint8_t);
void handleEvent7(AceButton*, uint8_t, uint8_t);

void button1Handler(AceButton* button, uint8_t eventType, uint8_t buttonState);
void button2Handler(AceButton* button, uint8_t eventType, uint8_t buttonState);
void button3Handler(AceButton* button, uint8_t eventType, uint8_t buttonState);
void button4Handler(AceButton* button, uint8_t eventType, uint8_t buttonState);
void button5Handler(AceButton* button, uint8_t eventType, uint8_t buttonState);
void button6Handler(AceButton* button, uint8_t eventType, uint8_t buttonState);
void button7Handler(AceButton* button, uint8_t eventType, uint8_t buttonState);

void manual_switch_setup()
{
   // Configure the input GPIOs

  pinMode(switch2, INPUT_PULLUP);
  pinMode(switch3, INPUT_PULLUP);
  pinMode(switch4, INPUT_PULLUP);
  pinMode(switch5, INPUT_PULLUP);
  pinMode(switch6, INPUT_PULLUP);
  pinMode(switch7, INPUT_PULLUP);
  
  config1.setEventHandler(button1Handler);
  config2.setEventHandler(button2Handler);
  config3.setEventHandler(button3Handler);
  config4.setEventHandler(button4Handler);
  config5.setEventHandler(button5Handler);
  config6.setEventHandler(button4Handler);
  config7.setEventHandler(button5Handler);

  button1.init(switch1);
  button2.init(switch2);
  button3.init(switch3);
  button4.init(switch4);
  button5.init(switch5);
  button6.init(switch6);
  button7.init(switch7);
}

//functions for defineing manual switch

void button1Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  if (DEBUG_SWITCH)Serial.println("EVENT1");
  switch (eventType) {
    case AceButton::kEventPressed:
      if (DEBUG_SWITCH)Serial.println("kEventPressed");
      Relay_Control(1 , ON);
      break;
    case AceButton::kEventReleased:
      if (DEBUG_SWITCH)Serial.println("kEventReleased");
      Relay_Control(1 , OFF);
      break;
  }
}
void button2Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  if (DEBUG_SWITCH)Serial.println("EVENT2");
  switch (eventType) {
    case AceButton::kEventPressed:
    
      if (DEBUG_SWITCH)Serial.println("kEventPressed");
      Relay_Control(2 , ON);
      break;
    case AceButton::kEventReleased:
      if (DEBUG_SWITCH)Serial.println("kEventReleased");
       Relay_Control(2 , OFF);
      break;
  }

  
}
void button3Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  if (DEBUG_SWITCH)Serial.println("EVENT3");
  switch (eventType) {
    case AceButton::kEventPressed:
      if (DEBUG_SWITCH)Serial.println("kEventPressed");
      Relay_Control(3 , ON);
    break;
    case AceButton::kEventReleased:
      if (DEBUG_SWITCH)Serial.println("kEventReleased");
      Relay_Control(3 , OFF);
      break;
  }
}
void button4Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  if (DEBUG_SWITCH)Serial.println("EVENT4");
  switch (eventType) {
    case AceButton::kEventPressed:
      if (DEBUG_SWITCH)Serial.println("kEventPressed");
        Relay_Control(4 , ON);
      break;
    case AceButton::kEventReleased:
      if (DEBUG_SWITCH)Serial.println("kEventReleased");
        Relay_Control(4 , OFF);
      break;
  }
}

void button5Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
 if (DEBUG_SWITCH)Serial.println("EVENT5");
  switch (eventType) {
    case AceButton::kEventPressed:
      if (DEBUG_SWITCH)Serial.println("kEventPressed");
         Relay_Control(5 , ON);
      break;
    case AceButton::kEventReleased:
      if (DEBUG_SWITCH)Serial.println("kEventReleased");
         Relay_Control(5 , OFF);
      break;
  }
}

void button6Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
 if (DEBUG_SWITCH)Serial.println("EVENT6");
  switch (eventType) {
    case AceButton::kEventPressed:
      if (DEBUG_SWITCH)Serial.println("kEventPressed");
         Relay_Control(6 , ON);
      break;
    case AceButton::kEventReleased:
      if (DEBUG_SWITCH)Serial.println("kEventReleased");
         Relay_Control(6 , OFF);
      break;
  }
}

void button7Handler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
 if (DEBUG_SWITCH)Serial.println("EVENT7");
  switch (eventType) {
    case AceButton::kEventPressed:
      if (DEBUG_SWITCH)Serial.println("kEventPressed");
         Relay_Control(7 , ON);
      break;
    case AceButton::kEventReleased:
      if (DEBUG_SWITCH)Serial.println("kEventReleased");
         Relay_Control(7 , OFF);
      break;
  }
}







void manual_switch_loop()
{
  button1.check();
  button2.check();
  button3.check();
  button4.check();
  button5.check();
  button6.check();
  button7.check();
}






















#endif //MANUAL_SWITCH_H
