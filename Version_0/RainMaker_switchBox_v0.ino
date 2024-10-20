#ifndef _SWITCHBOX_H
#define _SWITCHBOX_H

#define MANUAL_SWITCH  // if you comment this macro Manual switches will disabled
#define IR_REMOTE      // if you comment this macro Manual switches will disabled

#ifdef MANUAL_SWITCH
  #include "Manual_Switch.h"
#endif
#ifdef IR_REMOTE  
  #include "IR_Remote_Control.h"
#endif

#include "RainMaker_fun.h"
#include "Relay.h"

// for Turning On and Off the Serial Monitor
#define DEBUG_SW 1

void Wifi_check_loop()
{
  // Read GPIO0 (external button to gpio_reset device
  if (digitalRead(gpio_reset) == LOW) {
    //Push button pressed
    if (DEBUG_SW)Serial.printf("reset Button Pressed!\n");
    // Key debounce handling
    delay(100);
    int startTime = millis();
    while (digitalRead(gpio_reset) == LOW) delay(50);
    int endTime = millis();

    if ((endTime - startTime) > 5000) {
      // If key pressed for more than 5secs, reset all
      if (DEBUG_SW)Serial.printf("reset to factory.\n");
      RMakerFactoryReset(2);
    }
  }
  delay(100);

  if (WiFi.status() != WL_CONNECTED)
  {
    if (0)Serial.println("WiFi Not Connected");

  }
  else
  {
    if (0)Serial.println("WiFi Connected");
    if (Timer.isReady()) {  // Timer created in Rainmaker_fun.h for periodic sensor value update but now not using , this is for future use
      if (DEBUG_SW)Serial.println("Sending Sensor Data");
//      sendSensor();
      Timer.reset();      // Reset a second timer
    }
  }
}



void setup()
{
  if (DEBUG_SW)Serial.begin(115200);
  
#ifdef MANUAL_SWITCH  
  manual_switch_setup();
#endif  
#ifdef IR_REMOTE
  ir_remote_setup();
#endif 

 Relay_setup();
 Rain_Maker_Setup();

}

void loop()
{
#ifdef MANUAL_SWITCH  
  manual_switch_loop();
#endif  
#ifdef IR_REMOTE
  ir_remote_loop(); //IR remote Control
#endif

 Wifi_check_loop(); 
}



#endif //_SWITCHBOX_H
