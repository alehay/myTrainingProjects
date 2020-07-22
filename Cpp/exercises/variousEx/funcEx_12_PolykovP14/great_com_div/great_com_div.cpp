#include <iostream>


int evklid (int firstNum , int sekondNum ) {
    if ( firstNum < sekondNum ) {
       int temp =  firstNum;
       firstNum = sekondNum;
       sekondNum = temp;
    }
    int remainder {1};
    int quotient {0};

    while ( remainder != 0 ){
        quotient = firstNum/sekondNum;
        remainder = firstNum - sekondNum * quotient ;
             if (remainder == 0 ) {return sekondNum;}

        firstNum = sekondNum;
        sekondNum = remainder;
    }
    return remainder;
}


//very simple algorithm for finding the greatest common factor
int gfk (int  a , int b) {
    while (a != 0 && b != 0)
        if (a > b){
            a = a % b;
         }else{
            b = b % a;
        }
    return (a + b);
}


//greatest common factor
long long getGreatCommonFactor (long long a, long long b) {
    if(b==0)
        return a;
    return getGreatCommonFactor(b, a%b) ;}
