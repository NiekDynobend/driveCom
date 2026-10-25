#ifndef CAN_FRAME_H
#define CAN_FRAME_H

#include <array>
#include <cstdint>

//id 0x080  : emergence drive->controller
//id 0x180  : status drive-controller
//id 0x200  : command (controller->drive)
//idx 0x700 : heartbeat (both)

#define START_BYTE  0xAAu
#define CRC 0xFF
#define DATA_SIZE 8
#define CAN_DATA_SIZE 13

enum ParserState{
    PARSER_WAIT_SOF,
    PARSER_ID_LO,
    PARSER_ID_HI,
    PARSER_LEN,
    PARSER_DATA,
    PARSER_CRC
};

struct FrameDecoder{
    ParserState state;
    uint8_t data[DATA_SIZE];
};

struct CanFrame{
    uint16_t id;
    uint8_t len;
    uint8_t data[DATA_SIZE];
};

bool decodeFrame(const uint8_t*, CanFrame*);

bool encodeFrame(const CanFrame*, uint8_t*);

#endif