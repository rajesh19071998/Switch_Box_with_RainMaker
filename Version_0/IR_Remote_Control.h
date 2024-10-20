#ifndef _IR_REMOTE_CONTROL_H
#define _IR_REMOTE_CONTROL_H

#include <IRremote.h>     // https://github.com/Arduino-IRremote/Arduino-IRremote (3.6.1)
#include "Relay.h"

#define DEBUG_REMOTE 1

static uint8_t IR_SENS    = 17;  // IR Receiver Pin

// IR Remote Code for Relay
#define IR_Relay1           0x1FE50AF
#define IR_Relay2           0x1FED827
#define IR_Relay3           0x1FEF807
#define IR_Relay4           0x1FE30CF
#define IR_Relay5           0x1FE30C1
#define IR_Relay6           0x1FE30C2
#define IR_Relay7           0x1FE30C3

#define IR_Relay_All_Off    0x1FE48B7
#define IR_Relay_All_On     0x1FE7887

IRrecv irrecv(IR_SENS);
decode_results results;

void All_Lights_Off()
{
 Relay_Control(1 , OFF);
 Relay_Control(2 , OFF);
 Relay_Control(3 , OFF);
 Relay_Control(4 , OFF);
 Relay_Control(5 , OFF);
 Relay_Control(6 , OFF);
 Relay_Control(7 , OFF);

}

void All_Lights_On()
{
  Relay_Control(1 , ON);
  Relay_Control(2 , ON);
  Relay_Control(3 , ON);
  Relay_Control(4 , ON);
  Relay_Control(5 , ON);
  Relay_Control(6 , ON);
  Relay_Control(7 , ON);

}

void ir_remote_setup()
{
  irrecv.enableIRIn(); // Enabling IR sensor
}


/////////////////////////////////////////////////////////////////////// REMOTE //////////////////

void ir_remote() {
  if (0)Serial.println("Inside IR REMOTE");
  if (irrecv.decode(&results)) {
    if (DEBUG_REMOTE)Serial.println(results.value, HEX); //print the HEX code
    switch (results.value) {
      case IR_Relay1:
        if (DEBUG_REMOTE)Serial.println("IR_RELAY1 ON/OFF");
        if(Relay_State[0] == ON)
          Relay_Control(1 , OFF);
        else
          Relay_Control(1 , ON); 
        delay(100);
        break;
      case IR_Relay2:
        if (DEBUG_REMOTE)Serial.println("IR_RELAY2 ON/OFF");
        if(Relay_State[1] == ON)
          Relay_Control(2 , OFF);
        else
          Relay_Control(2 , ON);
        delay(100);
        break;
      case IR_Relay3:
        if (DEBUG_REMOTE)Serial.println("IR_RELAY3 ON/OFF");
        if(Relay_State[2] == ON)
          Relay_Control(3 , OFF);
        else
          Relay_Control(3 , ON);
        delay(100);
        break;
      case IR_Relay4:
        if (DEBUG_REMOTE)Serial.println("IR_RELAY4 ON/OFF");
        if(Relay_State[3] == ON)
          Relay_Control(4 , OFF);
        else
          Relay_Control(4 , ON);
        delay(100);
        break;
      case IR_Relay5:
        if (DEBUG_REMOTE)Serial.println("IR_RELAY5 ON/OFF");
        if(Relay_State[4] == ON)
          Relay_Control(5 , OFF);
        else
          Relay_Control(5 , ON);
        delay(100);
        break;
      case IR_Relay6:
        if (DEBUG_REMOTE)Serial.println("IR_RELAY6 ON/OFF");
        if(Relay_State[5] == ON)
          Relay_Control(6 , OFF);
        else
          Relay_Control(6 , ON);
        delay(100);
        break;
      case IR_Relay7:
        if (DEBUG_REMOTE)Serial.println("IR_RELAY7 ON/OFF");
        if(Relay_State[6] == ON)
          Relay_Control(7 , OFF);
        else
          Relay_Control(7 , ON);
        delay(100);
        break;
             
      case IR_Relay_All_Off:
        All_Lights_Off();
        break;
      case IR_Relay_All_On:
        All_Lights_On();
        break;

      default : break;
    }
    irrecv.resume();
  }
}




void ir_remote_loop() //IR remote Control
{
  ir_remote(); //IR remote Control
}


















#endif //_IR_REMOTE_CONTROL_H
