#ifndef _RELAY_H
#define _RELAY_H

#include "RainMaker_fun.h"

#define DEBUG_RELAY 1

#define RELAY_MAX_COUNT 7

uint8_t ON = 0;  // for relay control
uint8_t OFF = 1; // for relay control

//ESP32 usefull pins 2 ledpin , 4,13,16,17,18,19,23, 25,26,27,32,33 / I2C pins 21,22 /   input only pins 34,35,36,39
// GPIO for Relay (Appliance Control)

char Relay_Name[RELAY_MAX_COUNT][8] = {"Relay_1","Relay_2","Relay_3","Relay_4","Relay_5","Relay_6","Relay_7"}; // this name will show in App for relay control
uint8_t Relay_Pin[RELAY_MAX_COUNT] = {4,13,16,18,19,23,25}; //GPIO pin Numbers
uint8_t Relay_State[RELAY_MAX_COUNT]; 

 int Rainmaker_Relay_update_flag = 0; // it will give relay num
 int Manual_switch_update_flag = 0;

extern void Update_RainMaker_Relay_status(int Relay_Number); // updating latest Relay state in RainMaker APP 

void Relay_setup()
{
  for(int i=0;i<RELAY_MAX_COUNT ;i++)
  {
    pinMode(Relay_Pin[i], OUTPUT);
    digitalWrite(Relay_Pin[i], OFF);
    Relay_State[i] = OFF;
  }
}


void Relay_Control(int Relay_Number, int Mode)
{
  if((Relay_State[Relay_Number - 1] != Mode) && ( Relay_Number <= RELAY_MAX_COUNT))
  {
    digitalWrite(Relay_Pin[Relay_Number - 1] , Mode);
    Relay_State[Relay_Number - 1] = Mode;
    
    if(DEBUG_RELAY) {
      Serial.print("Relay  : ");
      Serial.print(Relay_Number);
      Serial.print(" State changed to : ");
      Serial.println(Mode);
    }
    Update_RainMaker_Relay_status(Relay_Number);
  } 
}














#endif //RELAY_H
