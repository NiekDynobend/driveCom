#include "ui/user_interface.h"


UserInterface::UserInterface(Interface& interface)
    : interface_(interface){}


void UserInterface::run(){
    std::string txt_input{""};

    std::cin>>txt_input;

    if(txt_input=="connect"){
        interface_.mtx.lock();
        interface_.command.connect = true;
        interface_.mtx.unlock();
    }
}