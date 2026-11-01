#include <iostream>
#include <thread>
#include <mutex>

#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

struct CommandInterface{
    bool connect{false};
    bool disconnect{false};
    bool ping{false};
};

struct StatusInterface{
    bool connected{false};
};

struct Interface{
    CommandInterface command;
    StatusInterface status;
    std::mutex mtx;
};


class UserInterface{
    public:
        UserInterface(Interface&);

        void run();

    private:
        Interface& interface_;
};

#endif