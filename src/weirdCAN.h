#pragma one
#include <Arduino.h>

#define DEBUG 0

/* Symbolic names for bit rate of CAN message                                */
typedef enum {CAN_50KBPS, CAN_100KBPS, CAN_125KBPS, CAN_250KBPS, CAN_500KBPS, CAN_1000KBPS} BITRATE;

/* Symbolic names for formats of CAN message                                 */
typedef enum {STANDARD_FORMAT = 0, EXTENDED_FORMAT} CAN_FORMAT;

/* Symbolic names for type of CAN message                                    */
typedef enum {DATA_FRAME = 0, REMOTE_FRAME}         CAN_FRAME;

typedef struct
{
  uint32_t id;        /* 29 bit identifier                               */
  uint8_t  data[8];   /* Data field                                      */
  uint8_t  len;       /* Length of data field in bytes                   */
  uint8_t  ch;        /* Object channel(Not use)                         */
  uint8_t  format;    /* 0 - STANDARD, 1- EXTENDED IDENTIFIER            */
  uint8_t  type;      /* 0 - DATA FRAME, 1 - REMOTE FRAME                */
} CAN_msg_t;

typedef const struct
{
  uint8_t TS2;
  uint8_t TS1;
  uint8_t BRP;
} CAN_bit_timing_config_t;

CAN_bit_timing_config_t can_configs[6] = {{2, 12, 56}, {2, 12, 28}, {2, 13, 21}, {2, 11, 12}, {2, 11, 6}, {1, 5, 6}};


class WeirdCAN
{

public:
    WeirdCAN() {};
    ~WeirdCAN() {};

    void printRegister(const char * buf, uint32_t reg);
    void CANSetGpio(GPIO_TypeDef * addr, uint8_t index, uint8_t speed);
    void CANSetFilter(uint8_t index, uint8_t scale, uint8_t mode, uint8_t fifo, uint32_t bank1, uint32_t bank2);
    bool CANInit(BITRATE bitrate, int remap);
    void CANReceive(uint8_t ch, CAN_msg_t* CAN_rx_msg);
    void CANSend(uint8_t ch, CAN_msg_t* CAN_tx_msg);
    uint8_t CANMsgAvail(uint8_t ch);

private:

};
