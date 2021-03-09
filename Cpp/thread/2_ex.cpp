#include <iostream>
#include <thread>

void func (std::string s)  
{
    for (int i = 0 ; i < 3 ; ++i)
    std::cout << "tread print " << s << std::endl;
}

int main (int argc , char * argv []) {
    
    std::thread trd (func, "123" );
    trd.join();
    return 0;
}