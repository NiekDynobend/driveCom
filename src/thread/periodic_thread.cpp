#include "thread/periodic_thread.h"


PeriodicThread::PeriodicThread(
    std::chrono::milliseconds period, 
    std::function<void()> function)
: period_(period), thread_function_(std::move(function)){}

void PeriodicThread::start(){
    running_ = true;
}

void PeriodicThread::stop(){
    running_ = false;
    //if joinable? maybe
    thread_.join();
}

void PeriodicThread::run(){
    auto next = std::chrono::steady_clock::now(); 

    while(running_){
        thread_function_();

        next += period_;
        if (std::chrono::steady_clock::now() > next) {      // the work took longer than one period                                   // (only if you added this member)
            next = std::chrono::steady_clock::now();        // restart the schedule from now
        }

        std::this_thread::sleep_until(next);                // sleep until the deadline
    }

}