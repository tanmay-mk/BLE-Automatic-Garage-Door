/*
 * File Name: ble.c
 *
 * Author:  Tanmay Mahendra Kothale (tanmay-mk)
 *
 */

/*  LIBRARY FILES   */
#include "gatt_db.h"

/*  OTHER FILES TO BE INCLUDED  */
#include "ble.h"
#include "lcd.h"
#include "scheduler.h"

// Include logging for this file
#define INCLUDE_LOG_DEBUG 1
#include "src/log.h"

/*  MACROS  */
#define ADVERTISE_INTERVAL_MIN        400   /*400*0.625ms = 250ms*/
#define ADVERTISE_INTERVAL_MAX        400   /*400*0.625ms = 250ms*/
#define ADVERTISE_MAX_EVENTS          0
#define ADVERTISE_DURATION            0

#define MIN_INTERVAL                  60    /*60*1.25ms = 75ms*/
#define MAX_INTERVAL                  60    /*60*1.25ms = 75ms*/
#define SLAVE_LATENCY                 4     /*4*75ms = 300ms*/
#define SUPERVISORY_TIMEOUT           4515  /*10ms * 4515 = 45150ms*/
#define MIN_CE_LENGTH                 0
#define MAX_CE_LENGTH                 0xFFFF

// BLE private data
ble_data_structure_t ble_data;

/*  GLOBAL VARIABLES  */
bool volatile indications, bonded, ongoing_operation_indication;

ble_data_structure_t* getBLEdata()
{
  return &ble_data;
}

void handle_ble_event(sl_bt_msg_t *evt)
{
  ble_data_structure_t* data = getBLEdata();
  sl_status_t sc = 0;
  switch (SL_BT_MSG_ID(evt->header)) {

/*#####################################################################################
     EVENTS COMMON TO SERVER AND CLIENTS
######################################################################################*/

/*---------------------------------------------------------------------------------------------*/
    case sl_bt_evt_system_boot_id:

      displayInit();

      bonded = false;

      //display the board as server
      displayPrintf(DISPLAY_ROW_NAME,"%s", "Server");
      //display assignment number
      displayPrintf(DISPLAY_ROW_ASSIGNMENT, "%s", "Course Project");

      //get address of the advertising ble device
      sc = sl_bt_system_get_identity_address(&data->myAddress, &data->addressType);

      //Configure the security manager with MITM protection,
      //Encryption requires bonding, Secure connections only
      sc = sl_bt_sm_configure(0x0F, sl_bt_sm_io_capability_displayyesno);

      //delete the data of previously bonded devices
      sc = sl_bt_sm_delete_bondings();

      //create a set for advertising
      sc = sl_bt_advertiser_create_set(&data->advertisingSetHandle);

      //set parameters for advertising
      sc = sl_bt_advertiser_set_timing(data->advertisingSetHandle,
                                       ADVERTISE_INTERVAL_MIN,
                                       ADVERTISE_INTERVAL_MAX,
                                       ADVERTISE_DURATION,
                                       ADVERTISE_MAX_EVENTS);

      //start advertising
      sc = sl_bt_advertiser_start(data->advertisingSetHandle,
                                  sl_bt_advertiser_general_discoverable,
                                  sl_bt_advertiser_connectable_scannable);

      //display "Advertising on the server device"
      displayPrintf(DISPLAY_ROW_CONNECTION,"%s", "Advertising");

      //display device address on the server device
      displayPrintf(DISPLAY_ROW_BTADDR, "%x:%x:%x:%x:%x:%x",
                    data->myAddress.addr[0], data->myAddress.addr[1],
                    data->myAddress.addr[2], data->myAddress.addr[3],
                    data->myAddress.addr[4], data->myAddress.addr[5]);

      if(sc == SL_STATUS_OK)
      {
          printf("%ld sec: BOOT COMPLETE, WAITING FOR CONNECTION!\n\r", letimerMilliseconds());
      }
      else{
          printf("%ld sec: BOOT FAILED WITH ERROR CODE %lu.\n\r",letimerMilliseconds(), sc);
      }
      break;
/*---------------------------------------------------------------------------------------------*/
    case sl_bt_evt_system_soft_timer_id:
      displayUpdate();
      break;
/*---------------------------------------------------------------------------------------------*/
    case sl_bt_evt_connection_opened_id:

      //clear the status flag variable
      sc = 0;

      //if connection is opened, stop advertising
      sc = sl_bt_advertiser_stop(data->advertisingSetHandle);

      //set parameters for the sending the data to client
      sc = sl_bt_connection_set_parameters(evt->data.evt_connection_opened.connection,
                                           MIN_INTERVAL,
                                           MAX_INTERVAL,
                                           SLAVE_LATENCY,
                                           SUPERVISORY_TIMEOUT,
                                           MIN_CE_LENGTH,
                                           MIN_CE_LENGTH);

      printf("%ld sec: CONNECTION OPENED!\n\r", letimerMilliseconds());

      displayPrintf(DISPLAY_ROW_CONNECTION,"%s", "Connected");

      break;
/*---------------------------------------------------------------------------------------------*/
    case sl_bt_evt_connection_closed_id:

      //clear status flag variable
      sc = 0;

      //delete data of previously bonded devices
      sc = sl_bt_sm_delete_bondings();

      //start advertising again
      sc = sl_bt_advertiser_start(data->advertisingSetHandle,
                                  sl_bt_advertiser_general_discoverable,
                                  sl_bt_advertiser_connectable_scannable);

      printf("%ld sec: CONNECTION CLOSED!\n\r", letimerMilliseconds());

      displayPrintf(DISPLAY_ROW_CONNECTION,"%s", "Advertising");

      //clear the temperature value row of server
      displayPrintf(DISPLAY_ROW_TEMPVALUE,"%s","");

      break;

    /*#####################################################################################
         EVENTS FOR SERVER
    ######################################################################################*/
/*---------------------------------------------------------------------------------------------*/
    case sl_bt_evt_gatt_server_characteristic_status_id:
      if(evt->data.evt_gatt_server_characteristic_status.characteristic == gattdb_distance_value &&
          evt->data.evt_gatt_server_characteristic_status.status_flags == sl_bt_gatt_server_client_config)
        {
          if(evt->data.evt_gatt_server_characteristic_status.client_config_flags ==  sl_bt_gatt_server_indication)
            {
              //indications are enabled
              indications = 1;
              data->connectionHandle =  evt->data.evt_gatt_server_characteristic_status.connection;
              printf("%ld sec: Distance Indications Enabled\n\r", letimerMilliseconds());
              gpioLed0SetOn();
            }
          //Indications are disabled
          else
            {
              indications = 0;
              ongoing_operation_indication = 0;
              displayPrintf(DISPLAY_ROW_TEMPVALUE, "%s", "");
              printf("%ld sec: Distance Indications Disabled\n\r",letimerMilliseconds());
              gpioLed0SetOff();
            }
        }

      else if(evt->data.evt_gatt_server_characteristic_status.status_flags == sl_bt_gatt_server_confirmation){

          ongoing_operation_indication = 0; //turn off in-flight indication when acknowledgment received from client
      }
      else
      {
              ongoing_operation_indication = 0;
              printf("%ld sec: Distance Indications Disabled\n\r", letimerMilliseconds());
              displayPrintf(DISPLAY_ROW_TEMPVALUE, "%s", "");
      }
      break;
/*---------------------------------------------------------------------------------------------*/
    //an indication to request to display the passkey to the user
  case sl_bt_evt_sm_passkey_display_id:
     displayPrintf(DISPLAY_ROW_PASSKEY,"Passkey = %lu",evt->data.evt_sm_passkey_display.passkey);
     printf("%ld sec: PASSKEY DISPLAYED: %lu\n\r",  letimerMilliseconds(), evt->data.evt_sm_passkey_display.passkey);
    break;
/*---------------------------------------------------------------------------------------------*/
  case sl_bt_evt_sm_passkey_request_id:
    printf("%ld sec: PASSKEY REQUESTED.\n\r",  letimerMilliseconds());
    break;
/*---------------------------------------------------------------------------------------------*/
  //Indicates a request for passkey display and confirmation by the user
  case sl_bt_evt_sm_confirm_passkey_id:
    //store the passkey for future use
    data->passkey = evt->data.evt_sm_confirm_passkey.connection;
    displayPrintf(DISPLAY_ROW_PASSKEY,"%lu",evt->data.evt_sm_confirm_passkey.passkey);
    sc = sl_bt_sm_passkey_confirm(data->passkey,1);
    //displayPrintf(DISPLAY_ROW_ACTION,"%s","Press PB0 to confirm.");
    printf("%ld sec: PASSKEY TO BE CONFIRMED: %lu\n\r", letimerMilliseconds(), evt->data.evt_sm_passkey_display.passkey);
    break;
/*---------------------------------------------------------------------------------------------*/
    //Triggered after the pairing or bonding procedure is successfully completed
   case sl_bt_evt_sm_bonded_id:
     bonded = true;
     displayPrintf(DISPLAY_ROW_CONNECTION, "%s", "Bonded");
     displayPrintf(DISPLAY_ROW_9,"%s", "");
     displayPrintf(DISPLAY_ROW_ACTION,"%s","");
     displayPrintf(DISPLAY_ROW_PASSKEY,"%s","");
     printf("%ld sec: BONDING COMPLETE WITH CLIENT\n\r", letimerMilliseconds());
     break;
/*---------------------------------------------------------------------------------------------*/
   //Indicates a user request to display that the new bonding request is received and for the user to confirm the request
   case sl_bt_evt_sm_confirm_bonding_id:
     sc = 0;
     sc = sl_bt_sm_bonding_confirm(evt->data.evt_sm_confirm_bonding.connection, 1);
     printf("%ld sec: BONDING REQUESTED BY CLIENT.\n\r", letimerMilliseconds());
     break;
/*---------------------------------------------------------------------------------------------*/
    case sl_bt_evt_gatt_server_indication_timeout_id:
      //printf("Confirmation not received from client\n\r");
      break;
/*---------------------------------------------------------------------------------------------*/
    //This event is triggered if the pairing or bonding procedure fails
    case sl_bt_evt_sm_bonding_failed_id:
      sc = 0;
      sc = sl_bt_connection_close(evt->data.evt_sm_bonding_failed.connection);
      printf("%ld sec: BONDING WITH CLIENT FAILED\n\r",letimerMilliseconds());
      break;
/*---------------------------------------------------------------------------------------------*/
    case sl_bt_evt_connection_parameters_id:
      //log connection parameters here
      break;
/*---------------------------------------------------------------------------------------------*/
    case sl_bt_evt_system_external_signal_id:
      data->evt = sl_bt_evt_system_external_signal_id;
      break;
/*---------------------------------------------------------------------------------------------*/
  } //switch
} //handle_ble_event
