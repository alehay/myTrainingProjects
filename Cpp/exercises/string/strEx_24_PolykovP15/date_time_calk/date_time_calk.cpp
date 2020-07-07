#include <iostream>
#include "date_time_calk.h"
//#include <vector>

//get a date and time from the user with a character check
// the number is represented in the writeback

std::string getTimeDateFromUser () {
    std::string timeDate;
    bool isInputAccept {false};
    while ( !(isInputAccept) ) {
        std::cout << "Enter a time format hh.mm dd.mm.yyyy : ";
        std::getline(std::cin , timeDate);
        // check for previous retrieval varible value
        if( std::cin.fail() ) {
            std::cin.clear();              // reloading cin
            std::cin.ignore( 32767,'\n' );   // clear buffer
            std::cout << "Oops, that input is invalid.  Please try again.\n";
            isInputAccept = false;
        } else {
            // std::cin.ignore(32767,'\n');   // clear excess
            isInputAccept = true;
            for (int i = 0; i < timeDate.size(); ++i ){
                timeDate[i] = ansii2intConvert (timeDate[i]);

            }
        }
    }
    return timeDate;
}

int ansii2intConvert (char ansii) {
    int temp = static_cast <int> (ansii);
    int num {-1} ; // -1 base case of excp
    // number simbol to number
    if ( (temp >= 48) && (temp <= 57) )  {
        num = temp - 48 ;
    }
    // capital letter to number A - 11
    if ( (temp >= 65) && (temp <= 90) )  {
        num = temp - (65 - 11);
    }
    // letter to number a - 11
    if ( (temp >= 97) && (temp <= 122) ) {
        num = temp - (97 - 11);
    }
    return num;
}

int timeDateToSec ( std::string * time ) {
    //extract years
    int indexStr = time->size () -1;
    int years {0};
    for (int i = 0; i <= indexStr ; ++i ) {
        if ( (time->at(indexStr - i) < 0 ) || (time->at(indexStr - i) > 9 )  ) {
             break;
             time->pop_back ();
        } else {
            years = years + time->at(indexStr - i) * pow(10, i);
        }
    }
    int sec = years * 31536000;
    return sec;
}

int pow(int num , int exp) {
    int temp = 1;
    while (exp > 0) {
        // multiplay
        if (exp % 2 ) {
            temp *= num ;
            --exp ;
        }
        //squared
        exp /=2;
        num *= num;
    }
    return temp;
}
