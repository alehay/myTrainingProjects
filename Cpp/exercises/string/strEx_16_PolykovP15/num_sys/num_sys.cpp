#include <iostream>
#include <string>
#include <vector>
#include "num_sys.h"

//get a number from the user with a character check
// the number is represented in the writeback
std::string getBigNumUser () {
    std::string bigStringNum;
    bool isInputAccept {false};
    while ( !(isInputAccept) ) {
        std::cout << "Enter a Number : ";
        std::cin >> bigStringNum;
        // check for previous retrieval varible value
        if( std::cin.fail() ) {
            std::cin.clear();              // reloading cin
            std::cin.ignore( 32767,'\n' );   // clear buffer
            std::cout << "Oops, that input is invalid.  Please try again.\n";
            isInputAccept = false;
        } else {
            std::cin.ignore(32767,'\n');   // clear excess
            isInputAccept = true;
            for (int i = 0; i < bigStringNum.size(); ++i  ){
                // if converter return -1 if char incorect
                if (ansii2intConvert(bigStringNum[i]) == -1 ) {
                    std::cout << "Oops, invalid character : " << bigStringNum [i] << std::endl;
                    isInputAccept = false;
                }
            }
        }
    }
    return bigStringNum;
}

//get base numeric systems
int getBaseNumUser () {
    while (true) {
        std::cout << "Enter a Base number in the range from 2 to 36: ";
        int baseNum ;
        std::cin >> baseNum ;
        // check for previous retrieval variable value
        if (std::cin.fail()) {
            std::cin.clear(); // reloading cin
            std::cin.ignore(32767,'\n'); // clear buffer
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        } else {
            std::cin.ignore(32767,'\n'); // clear excess
            if ( ( baseNum >= 2) && ( baseNum <= 36) ) {
                return baseNum;
            }
        }
    }
}

//converter ansii char simbol to int
int ansii2intConvert (char ansii) {
    int temp = static_cast<int>(ansii);
    int num {-1};
    // number simbol to number
    if ((temp >= 48) && (temp <= 57))  {
        num = temp - 48 ;
    }
    // capital letter to number A - 11
    if ((temp >= 65) && (temp <= 90))  {
        num = temp - (65 - 11);
    }
    // letter to number a - 11
    if ((temp >= 97) && (temp <= 122)) {
        num = temp - (97 - 11);
    }
    return num;
}

// converter int to ansii simbol
char int2ansiiConvert (int num) {
    char simbol {0};
    // number to namber simbol
    if ((num >= 0) && (num <= 9)) {
        simbol = num + 48 ;
    }
    // number to letter simbol
    if ((num >= 11) && (num <= 36)) {
        simbol = num + (97-11) ;
    }
    return  simbol;
}

void converterBase2Base (bigNum * InitNum) {

    for (int i = 0; i <  InitNum->mantissa.size() ; ++i )
        InitNum->mantissa [i] ;
}

//summ long number func
void getSumm (bigNum * aNum, bigNum * bNum, bigNum * resultNum) {
    // identify a larger number
    bigNum * bigestNum;
    bigNum * smallerNum;
    if (aNum->mantissa.size() > bNum->mantissa.size()) {
       bigestNum = aNum ;
       smallerNum = bNum;
    } else {
       bigestNum = bNum ;
       smallerNum = aNum;
    }
    //specify the number system
    resultNum->radix = bigestNum->radix;
    // addition of elements each with each
    int maxDigit =  bigestNum->mantissa.size();
    for (int i = 0 ; i < maxDigit; ++i) {
        if (i < smallerNum->mantissa.size()) {
            resultNum->mantissa.push_back (bigestNum->mantissa.at(i)
                                          + smallerNum->mantissa.at(i));
        } else {
            //short number is over
            resultNum->mantissa.push_back(bigestNum->mantissa.at(i));
        }
    }
    //add leading digit
    resultNum->mantissa.push_back(0);
    for (int i = 0; i < resultNum->mantissa.size() ; ++ i ) {
        if (resultNum->mantissa.at(i) >= resultNum->radix ) {
            resultNum->mantissa.at(i + 1) +=(resultNum->mantissa.at(i) / resultNum ->radix);
            resultNum->mantissa.at(i) = resultNum->mantissa.at(i) % resultNum->radix;
        }
    }
    // delet null leading digin
    if ( resultNum->mantissa.at(maxDigit) == 0 ) {
        resultNum->mantissa.pop_back();
    }
}


int max (int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int min (int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}
