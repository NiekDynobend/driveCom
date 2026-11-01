#include "frame.h"
#include "serial_port.h"
#include "ui/user_interface.h"

#ifndef FRAME_LINK_H
#define FRAME_LINK_H

class FrameLink{
    public:
        FrameLink(Interface&);


        // methods
        bool send(const CanFrame*);
        bool poll(CanFrame* );

        void run();
        

    private:
        bool connected{false};
        CanFrame received_frame_;
        CanFrame send_frame_;
        SerialPort serial_port_;
        Interface& ui_interface_;
};

#endif