#ifndef _RAINMAKER_FUN_H
#define _RAINMAKER_FUN_H

#include "RMaker.h"
#include "WiFi.h"
#include "WiFiProv.h"
#include <SimpleTimer.h>  // https://github.com/kiryanenko/SimpleTimer (1.0.0)

#include "Relay.h"

#define DEBUG_RAINMAKER 1

static uint8_t gpio_reset = 0;   // Reset Pin
/* Relay.h */
extern char Relay_Name[][8];
extern uint8_t Relay_Pin[];
extern uint8_t Relay_State[];
extern uint8_t ON;
extern uint8_t OFF;
extern void Relay_Control(int Relay_Number, int Mode);

 Switch my_switch1(Relay_Name[0] , &Relay_Pin[0]); //Switch is RainMaker parameter for App display(like switch)
 Switch my_switch2(Relay_Name[1] , &Relay_Pin[1]);
 Switch my_switch3(Relay_Name[2] , &Relay_Pin[2]);
 Switch my_switch4(Relay_Name[3] , &Relay_Pin[3]);
 Switch my_switch5(Relay_Name[4] , &Relay_Pin[4]);
 Switch my_switch6(Relay_Name[5] , &Relay_Pin[5]);
 Switch my_switch7(Relay_Name[6] , &Relay_Pin[6]);

SimpleTimer Timer;

// BLE Credentials
const char *service_name = "ESP32_SWITCH_BOX_BLE"; //name of node in BLE
const char *pop = "Rajesh1234"; //password
// define the Node Name
char nodeName[] = "SWITCH BOX";

void sysProvEvent(arduino_event_t *sys_event);

void write_callback(Device *device, Param *param, const param_val_t val, void *priv_data, write_ctx_t *ctx)
{
  int Status = 0;
  const char *device_name = device->getDeviceName();
  const char *param_name = param->getParamName();

  if (strcmp(device_name, Relay_Name[0]) == 0)
  {
    if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.printf("Switch value_1 = %s\n", val.val.b ? "true" : "false");

    if (strcmp(param_name, "Power") == 0)
    {
      if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.printf("Received value = %s for %s - %s\n", val.val.b ? "true" : "false", device_name, param_name);
      Status = val.val.b;
      (Status == false) ? Relay_Control(1 , ON) : Relay_Control(1 , OFF);
      param->updateAndReport(val);
    }

  } else if (strcmp(device_name, Relay_Name[1]) == 0) {

    if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.printf("SSwitch value_2 = %s\n", val.val.b ? "true" : "false");

    if (strcmp(param_name, "Power") == 0) {
      if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.printf("Received value = %s for %s - %s\n", val.val.b ? "true" : "false", device_name, param_name);
      Status = val.val.b;
      (Status == false) ? Relay_Control(2 , ON) : Relay_Control(2 , OFF);
      param->updateAndReport(val);
    }

  } else if (strcmp(device_name, Relay_Name[2]) == 0) {

    if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.printf("Switch value_3 = %s\n", val.val.b ? "true" : "false");

    if (strcmp(param_name, "Power") == 0) {
      if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.printf("Received value = %s for %s - %s\n", val.val.b ? "true" : "false", device_name, param_name);
      Status = val.val.b;
      (Status == false) ? Relay_Control(3 , ON) : Relay_Control(3 , OFF);
      param->updateAndReport(val);
    }

  } else if (strcmp(device_name, Relay_Name[3]) == 0)
  {

    if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.printf("Switch value_4 = %s\n", val.val.b ? "true" : "false");

    if (strcmp(param_name, "Power") == 0) {
      if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.printf("Received value = %s for %s - %s\n", val.val.b ? "true" : "false", device_name, param_name);
      Status = val.val.b;
      (Status == false) ? Relay_Control(4 , ON) : Relay_Control(4 , OFF);
      param->updateAndReport(val);
    }

  }else if (strcmp(device_name, Relay_Name[4]) == 0)
  {

    if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.printf("Switch value_5 = %s\n", val.val.b ? "true" : "false");

    if (strcmp(param_name, "Power") == 0) {
      if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.printf("Received value = %s for %s - %s\n", val.val.b ? "true" : "false", device_name, param_name);
      Status = val.val.b;
      (Status == false) ? Relay_Control(5 , ON) : Relay_Control(5 , OFF);
      param->updateAndReport(val);
    }

  } else if (strcmp(device_name, Relay_Name[5]) == 0)
  {

    if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.printf("Switch value_6 = %s\n", val.val.b ? "true" : "false");

    if (strcmp(param_name, "Power") == 0) {
      if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.printf("Received value = %s for %s - %s\n", val.val.b ? "true" : "false", device_name, param_name);
      Status = val.val.b;
      (Status == false) ? Relay_Control(6 , ON) : Relay_Control(6 , OFF);
      param->updateAndReport(val);
    }

  } else if (strcmp(device_name, Relay_Name[6]) == 0)
  {

    if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.printf("Switch value_7 = %s\n", val.val.b ? "true" : "false");

    if (strcmp(param_name, "Power") == 0) {
      if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.printf("Received value = %s for %s - %s\n", val.val.b ? "true" : "false", device_name, param_name);
      Status = val.val.b;
      (Status == false) ? Relay_Control(7 , ON) : Relay_Control(7 , OFF);
      param->updateAndReport(val);
    }
  }
  
  
}


void Update_RainMaker_Relay_status(int Relay_Number) // updating latest Relay state in RainMaker APP
{
  if(Relay_Number == 1){
    if(Relay_State[Relay_Number - 1])
       my_switch1.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, true);
    else
       my_switch1.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, false);  
    }
  else if(Relay_Number == 2){
    if(Relay_State[Relay_Number - 1])
       my_switch2.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, true);
    else
       my_switch2.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, false);  
    } 
  else if(Relay_Number == 3){
    if(Relay_State[Relay_Number - 1])
       my_switch3.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, true);
    else
       my_switch3.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, false);  
    }
  else if(Relay_Number == 4){
    if(Relay_State[Relay_Number - 1])
       my_switch4.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, true);
    else
       my_switch4.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, false);  
    }
  else if(Relay_Number == 5){
    if(Relay_State[Relay_Number - 1])
       my_switch5.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, true);
    else
       my_switch5.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, false);  
    }
  else if(Relay_Number == 6){
    if(Relay_State[Relay_Number - 1])
       my_switch6.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, true);
    else
       my_switch6.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, false);  
    }
  else if(Relay_Number == 7){
    if(Relay_State[Relay_Number - 1])
       my_switch7.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, true);
    else
       my_switch7.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, false);  
    }                
  
}

void Rain_Maker_Setup()
{
  pinMode(gpio_reset, INPUT);
  
   Node my_node;
  my_node = RMaker.initNode(nodeName);

  my_switch1.addCb(write_callback);
  my_node.addDevice(my_switch1);
  my_switch1.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, Relay_State[0]);
  delay(500);

  my_switch2.addCb(write_callback);
  my_node.addDevice(my_switch2);
  my_switch2.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, Relay_State[1]);
  delay(500);

  my_switch3.addCb(write_callback);
  my_node.addDevice(my_switch3);
  my_switch3.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, Relay_State[2]);
  delay(500);

  my_switch4.addCb(write_callback);
  my_node.addDevice(my_switch4);
  my_switch4.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, Relay_State[3]);
  delay(500);

  my_switch5.addCb(write_callback);
  my_node.addDevice(my_switch5);
  my_switch5.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, Relay_State[4]);
  delay(500);

  my_switch6.addCb(write_callback);
  my_node.addDevice(my_switch6);
  my_switch6.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, Relay_State[5]);
  delay(500);

  my_switch7.addCb(write_callback);
  my_node.addDevice(my_switch7);
  my_switch7.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, Relay_State[6]);
  delay(500);


Timer.setInterval(30000);

  //This is optional
  RMaker.enableOTA(OTA_USING_PARAMS);
  //If you want to enable scheduling, set time zone for your region using setTimeZone().
  //The list of available values are provided here https://rainmaker.espressif.com/docs/time-service.html
  // RMaker.setTimeZone("Asia/Shanghai");
  // Alternatively, enable the Timezone service and let the phone apps set the appropriate timezone
  RMaker.enableTZService();
  RMaker.enableSchedule();

  if (DEBUG_RAINMAKER)Serial.printf("\nStarting ESP-RainMaker\n");
  RMaker.start();

  WiFi.onEvent(sysProvEvent);
#if CONFIG_IDF_TARGET_ESP32
  WiFiProv.beginProvision(WIFI_PROV_SCHEME_BLE, WIFI_PROV_SCHEME_HANDLER_FREE_BTDM, WIFI_PROV_SECURITY_1, pop, service_name);
#else
  WiFiProv.beginProvision(WIFI_PROV_SCHEME_SOFTAP, WIFI_PROV_SCHEME_HANDLER_NONE, WIFI_PROV_SECURITY_1, pop, service_name);
#endif

 /*  in starting of MOdule all relays are off , so updating Rain Maker App  */
  my_switch1.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, false);
  my_switch2.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, false);
  my_switch3.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, false);
  my_switch4.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, false);
  my_switch5.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, false);
  my_switch6.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, false);
  my_switch7.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, false);
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sysProvEvent(arduino_event_t *sys_event)
{
  switch (sys_event->event_id)
  {
    case ARDUINO_EVENT_PROV_START:
      if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.printf("\nProvisioning Started with name \"%s\" and PoP \"%s\" on BLE\n", service_name, pop);
      printQR(service_name, pop, "ble");
      break;
    case ARDUINO_EVENT_WIFI_STA_GOT_IP:
      if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.print("\nConnected IP address : ");
      if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.println(IPAddress(sys_event->event_info.got_ip.ip_info.ip.addr));
      break;
    case ARDUINO_EVENT_WIFI_STA_DISCONNECTED:
      if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.println("\nDisconnected. Connecting to the AP again... ");
      break;
    case ARDUINO_EVENT_PROV_CRED_RECV:
      if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.println("\nReceived Wi-Fi credentials");
      if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.print("\tSSID : ");
      if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.println((const char *) sys_event->event_info.prov_cred_recv.ssid);
      if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.print("\tPassword : ");
      if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.println((char const *) sys_event->event_info.prov_cred_recv.password);
      break;
    case ARDUINO_EVENT_PROV_INIT:
      wifi_prov_mgr_disable_auto_stop(10000);
      break;
    case ARDUINO_EVENT_PROV_CRED_SUCCESS:
      if (DEBUG_RAINMAKER)if (DEBUG_RAINMAKER)Serial.println("Stopping Provisioning!!!");
      wifi_prov_mgr_stop_provisioning();
      break;
  }
}




#endif //_RAINMAKER_FUN_H
