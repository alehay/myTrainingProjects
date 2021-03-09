#include <iostream>
#include <thread>

#include <chrono> // sleep

#include <functional> // std::ref
 using namespace std::chrono_literals;
 
void func (std::string && s)  
{
     std::thread::id this_id = std::this_thread::get_id();
    for (int i = 0 ; i < 5 ; ++i)
    std::cout << "tread id " << this_id << " " << s << "\n" << std::endl;
}

void func_1 (std::string & s)  
{
     std::thread::id this_id = std::this_thread::get_id();
    for (int i = 0 ; i < 5 ; ++i)

    std::cout << "tread id " << this_id << " " << s << "\n" << std::endl;
}

int main (int argc , char * argv []) {
   
    
    auto start = std::chrono::high_resolution_clock::now();


    std::string string {"1_23"} ;

    std::string & ref_stting = string; 


    std::thread trd (func,ref_stting );
    std::this_thread::sleep_for (std::chrono::microseconds(1));
    string = "2_asdfgasd";
    std::thread trd1 (func,ref_stting );
    std::this_thread::sleep_for (std::chrono::microseconds(1));

    string = "3_asdfgasd";
    std::thread trd3 (func,ref_stting );
    std::this_thread::sleep_for (std::chrono::microseconds(1));

    trd.join();
    trd1.join();
    trd3.join();

    std::cout << "--------------- and using std::ref -----------"<< std::endl;  

    std::string string1 {"1_23"} ;
    
    std::string & ref_stting1 = string1; 
    std::thread trd_ (func_1, std::ref (ref_stting1));
    //std::this_thread::sleep_for (std::chrono::microseconds(1));
    string1 = "2_asdfgasd";
    std::thread trd_1 (func_1, std::ref (ref_stting1) );
    std::this_thread::sleep_for (std::chrono::microseconds(1));
    string1 = "3_asdfgasd";
    std::thread trd_3 (func_1, std::ref (ref_stting1) );
    std::this_thread::sleep_for (std::chrono::microseconds(1));
    trd_.join();
    trd_1.join();
    trd_3.join();



    return 0;
}