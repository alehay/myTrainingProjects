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
void converterBase2Base (bigNum * InitNum);
int max (int a, int b);
int min (int a, int b);
int pow(int num , int exp);
void straightenNum (bigNum * initNum) ;
void getSumm (bigNum* aNum , bigNum* bNum , bigNum* resultNum) ;
void getDifference (bigNum * aNum, bigNum * bNum, bigNum * resultNum) ;
void base2Bin (bigNum * aNum) ;

#endif // NUM_SYS_H
