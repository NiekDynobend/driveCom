#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdbool.h>
#include <iostream>

#ifndef SERIAL_PORT_H
#define SERIAL_PORT_H

class SerialPort{
    public:
        DCB dcb;      // serial config
        HANDLE hCom; //ticket
        TCHAR * pcCommPort = TEXT("COM7");
        SerialPort(){}


        void init();
        bool connect();
        bool write(uint8_t*, uint8_t);
};

#endif