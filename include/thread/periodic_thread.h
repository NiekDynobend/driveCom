#include <chrono>
#include <functional>
#include <thread>

#ifndef PERIODIC_THREAD_H
#define PERIODIC_THREAD_H

class PeriodicThread{
    public:
        PeriodicThread(std::chrono::milliseconds , std::function<void()>){}

        void start();
        void run();
        void stop();

    private:
        std::chrono::milliseconds period_;
        std::function<void()> thread_function_;
        std::thread thread_;
        std::atomic<bool> running_{false};
};

#endif