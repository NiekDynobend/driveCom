#include "frame_link.h"



bool FrameLink::send(const CanFrame* frame){
    if(frame==NULL){
        return false;
    }
    uint8_t encoded_data[CAN_DATA_SIZE];
    if(!encodeFrame(frame, encoded_data)){
        return false;
    }

    serial_port_.write(encoded_data, (uint8_t)CAN_DATA_SIZE);

}
bool FrameLink::poll(CanFrame* frame ){

}