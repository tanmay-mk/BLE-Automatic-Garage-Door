

#include "sl_bt_api.h"
#include <stdbool.h>
#include "em_common.h"
#include "sl_status.h"
#include "app_log.h"
#include "app_assert.h"
#include "sl_bluetooth.h"
#include "gatt_db.h"

#define UINT8_TO_BITSTREAM(p, n) { *(p)++ = (uint8_t)(n); }

#define UINT32_TO_BITSTREAM(p, n) { *(p)++ = (uint8_t)(n); *(p)++ = (uint8_t)((n) >> 8); \
  *(p)++ = (uint8_t)((n) >> 16); *(p)++ = (uint8_t)((n) >> 24); }

#define UINT32_TO_FLOAT(m, e) (((uint32_t)(m) & 0x00FFFFFFU) | (uint32_t)((int32_t)(e) << 24))


// BLE Data Structure, save all of our private BT data in here.
// Modern C (circa 2021 does it this way)
// typedef ble_data_struct_t is referred to as an anonymous struct definition
typedef struct {
// values that are common to servers and clients
bd_addr myAddress;
uint8_t addressType;
uint32_t evt;

// values unique for server
// The advertising set handle allocated from Bluetooth stack.
uint8_t   advertisingSetHandle;
uint8_t   connectionHandle;
uint32_t  passkey;

} ble_data_structure_t;

extern volatile bool indications,
                     ongoing_operation_indication,
                     bonded;

void handle_ble_event(sl_bt_msg_t *evt);
float gattFloat32ToInt(const uint8_t *value_start_little_endian);
ble_data_structure_t* getBLEdata(void);
