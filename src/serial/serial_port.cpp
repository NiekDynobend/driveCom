#include <iostream>
#include "serial/serial_port.h"

void SerialPort::init()
{
    std::cout<<"Init serial port." <<std::endl;
    dcb.DCBlength = sizeof(DCB);
    dcb.BaudRate = 115200;
    dcb.ByteSize = 8;
    dcb.Parity = NOPARITY;
    dcb.StopBits = ONESTOPBIT;
    dcb.fOutxCtsFlow = FALSE;
    dcb.fOutxDsrFlow = FALSE;
    dcb.fOutX = FALSE;
    dcb.fInX = FALSE;
    dcb.fBinary = TRUE;
    dcb.fDtrControl = DTR_CONTROL_ENABLE;
}

bool SerialPort::connect()
{
        std::cout<<"Connect serial port" << std::endl;
        hCom = CreateFile( pcCommPort,
                GENERIC_READ | GENERIC_WRITE,
                0,      //  must be opened with exclusive-access
                NULL,   //  default security attributes
                OPEN_EXISTING, //  must use OPEN_EXISTING
                0,      //  not overlapped I/O
                NULL ); //  hTemplate must be NULL for comm devices
        
        if(hCom==INVALID_HANDLE_VALUE)
        {
            std::cout<<"Create File Failed with Error: " << GetLastError() << std::endl;
            return false;
        }

        //  Initialize the DCB structure.
        SecureZeroMemory(&dcb, sizeof(DCB));

        //  Build on the current configuration by first retrieving all current
        //  settings.
        bool bSuccess = GetCommState(hCom, &dcb);
        if(bSuccess){
            std::cout<<"Connection Successfull!"<<std::endl;
            return bSuccess;
        }else{
            std::cout<<"getComState Failed with error:"<<GetLastError() << std::endl;
            return bSuccess;
        }
}


bool SerialPort::write(uint8_t*        data, uint8_t len){
    if(hCom == INVALID_HANDLE_VALUE || data==NULL){
        return false;
    }

    DWORD written = 0;                                  // Windows fills this in
    BOOL ok = WriteFile(hCom,                           // which port
                        data,                           // the bytes
                        static_cast<DWORD>(len),        // how many
                        &written,                       // out: how many were actually written
                        nullptr);                       // no async I/O

    return ok && written == len;  
}