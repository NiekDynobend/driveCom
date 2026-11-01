#include "thread/thread_timer.h"


ThreadTimer::ThreadTimer(
    std::chrono::milliseconds period, 
    std::function<void()> function)
: period_(period), thread_function_(std::move(function)){}

void ThreadTimer::start(){
    if(thread_.joinable()){
        return;
    }
    running_ = true;
    thread_ = std::thread(&ThreadTimer::run, this);
}

void ThreadTimer::stop(){
    running_ = false;
    if(thread_.joinable()){
        thread_.join();
    }
    thread_.join();
}

void ThreadTimer::run(){
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