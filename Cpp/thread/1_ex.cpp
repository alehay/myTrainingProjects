#include <iostream>
#include <thread>
//#include <pthread.h>

class background_task
{
public:
void do_something() const {
    std::cout << "do_something()" << std::endl;
}
void operator()() const
{
    do_something();
}
};

int main()
{
    background_task f;
    std::thread t(f);
    t.join();
}