#include<iostream>
#include "serial/frame_link.h"
#include "ui/user_interface.h"
#include "thread/thread_timer.h"

void main()
{
    Interface ui_interface;
    UserInterface ui(ui_interface);
    FrameLink frame_link(ui_interface);

    ThreadTimer ui_thread(
        std::chrono::milliseconds(100),
        std::bind(&UserInterface::run, &ui)
    );

    ThreadTimer frame_link_thread(
        std::chrono::milliseconds(100),
        std::bind(&FrameLink::run, &frame_link)
    );

    ui_thread.start();
    frame_link_thread.start();

    while(true){
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    ui_thread.stop();
    frame_link_thread.stop();

}