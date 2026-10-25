#include "frame.h"
#include "serial_port.h"

#ifndef FRAME_LINK_H
#define FRAME_LINK_H

class FrameLink{
    public:
        FrameLink(){
            serial_port_.connect();
        }


        // methods
        bool send(const CanFrame*);
        bool poll(CanFrame* );
        

    private:
        CanFrame received_frame_;
        CanFrame send_frame_;
        SerialPort serial_port_;
};

#endif