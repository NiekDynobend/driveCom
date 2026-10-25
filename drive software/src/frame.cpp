#include <iostream>

#include "frame.h"


bool encodeFrame(const CanFrame* frame, uint8_t* encoded_frame){
    if(frame==NULL){
        printf("Encoder received CanFrame==Null");
        return false;
    }
    if(encoded_frame==NULL){
        printf("encoder received encoded_frame==NULL");
        return false;
    }

    encoded_frame[0] = START_BYTE;
    encoded_frame[1] = (uint8_t)(frame->id);
    encoded_frame[2] = (uint8_t)((frame->id)>>8);
    encoded_frame[3] = frame->len;
    
    for(int idx=0; idx<DATA_SIZE; idx++){
        encoded_frame[4+idx] = frame->data[idx];
    }
    encoded_frame[12] = CRC;
    return true;
}

bool decodeFrame(const uint8_t* encoded_frame, CanFrame* decoded_frame){
    if(encoded_frame==NULL || decoded_frame==NULL){
        std::cout <<"Decoder: either encoded frame or canFrame is NULL."<<std::endl;
        return false;
    }
    if(encoded_frame[0]!=START_BYTE){
        std::cout<<"Decoder: First byte of encoded frame is not equal to start byte" <<std::endl;
        return false;
    }
    if(encoded_frame[3]>DATA_SIZE){
        std::cout<<"Decoder: data length is larger than max size of 8." << std::endl;
        return false;
    }

    decoded_frame->id = (uint16_t)(encoded_frame[1] | (encoded_frame[2] << 8));
    decoded_frame->len = encoded_frame[3];
    for(int idx=0; idx<DATA_SIZE; idx++){
        decoded_frame->data[idx] = encoded_frame[4+idx];
    }
    return true;
}

