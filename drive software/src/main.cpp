#include<iostream>
#include "serial_port.h"

void main()
{
    SerialPort serial_port;
    serial_port.init();
    serial_port.connect();
}