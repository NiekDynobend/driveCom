#ifndef DRIVE_PROTOCOL_H
#define DRIVE_PROTOCOL_H

enum message_id
{
    STATUS_ID = 0x100,
    COMMAND_ID = 0x200
};

enum control_word
{
    ENABLE = 0x0000,
    DISABLE = 0x0001
};

enum status_word
{
    STATE = 0x000
};

#endif