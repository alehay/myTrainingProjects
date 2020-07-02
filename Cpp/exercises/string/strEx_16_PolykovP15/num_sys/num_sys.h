#ifndef NUM_SYS_H
#define NUM_SYS_H
#include <vector>


struct bigNum {
    bool isNegative ; // sign
    int radix; //the base of a system of numeration
    std::vector <int> mantissa ;
};


std::string getBigNumUser ();
int getBaseNumUser ();
int ansii2intConvert (char ansii);
char int2ansiiConvert (int num);

#endif // NUM_SYS_H
