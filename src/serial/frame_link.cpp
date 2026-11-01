#include "serial/frame_link.h"

FrameLink::FrameLink(Interface& ui_interface)
    : ui_interface_(ui_interface)
    {}

bool FrameLink::send(const CanFrame* frame){
    if(frame==NULL){
        return false;
    }
    uint8_t encoded_data[CAN_DATA_SIZE];
    if(!encodeFrame(frame, encoded_data)){
        return false;
    }

    serial_port_.write(encoded_data, (uint8_t)CAN_DATA_SIZE);
    return true;

}
bool FrameLink::poll(CanFrame* frame ){
    return true;
}

void FrameLink::run(){
    ui_interface_.mtx.lock();
    CommandInterface& cmd = ui_interface_.command;
    
    if(cmd.connect){
        std::cout<<"call connect" << std::endl;
        serial_port_.connect();
        cmd.connect = false;
    }
    if(cmd.ping){
        FrameLink::send(&send_frame_);
    }
    ui_interface_.mtx.unlock();


    // poll every cycle
    poll(&received_frame_);
}