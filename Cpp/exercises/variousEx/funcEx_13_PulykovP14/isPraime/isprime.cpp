#include <iostream>
#include <cstdlib>

unsigned long long int getNumUser () {
    while (true) {
        std::cout << "Enter a int value: " ;
        unsigned long a {0} ;
        std::cin >> a;
        // check for previous retrieval varible value
        if (std::cin.fail()) {
            std::cin.clear(); // reloading cin
            std::cin.ignore(32767,'\n'); // clear buffer
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        } else {
            std::cin.ignore(32767,'\n'); // clear excess
            return a;
        }
    }
}

bool isEvenNum (unsigned long long int num) {
    //fast parity using bit operations
    // an even number is NOT prime
    return ( !(num & 1) );
}

unsigned long long getGreatCommonFactor (unsigned long long a,unsigned long long b){
    //simple algorithm Evklid
    while (a != 0 && b != 0) {
        if (a > b){
            a = a % b;
        } else {
            b = b % a;
        }
    }
    return (a + b);
}

unsigned long long mul(unsigned long long a, unsigned long long b, unsigned long long m){
//modulation for exponentiation
    if(b <= 1)
        return a;
    if(b % 2 == 0) {
        unsigned long long t = mul(a, b / 2, m);
        return (2 * t) % m;
    }
    return ( mul(a, b - 1, m) + a) % m;
}

//binary exponentiation:
// if the exponent is even :
//          a^b = ( a^(b/2) )^2 = ( a^(b/2) ) * ( a^(b/2) )
// else :
//          a^b = ( a^(b-1) )*a
// recursive exponentiation where in the tail
// of the recursion is multiplication in function MUL
unsigned long long pows(unsigned long long a, unsigned long long b, unsigned long long m){
    if(b == 0) {
        return 1;
    }
    if(b % 2 == 0) {
        unsigned long long t = pows(a, b / 2, m);
        return mul(t , t, m) % m;
    }
    return ( mul( pows( a, b - 1, m) , a, m) ) % m;
}

// Fermat's little theorem:
// a - integer not divisible by P
// a^num = a % num <<equivalently>>  a^(num-1) = 1 % num
// only if their greatest common factor 1 >> GKF( A and NUM ) = 1
// and and num is prime
bool isPrimeFerma (unsigned long long int num) {
    if(num == 2) {
        return true;
    }
    if ( isEvenNum(num) ) {
        return false;
    }
    srand( time(NULL) );
    for(int i = 0; i < 100; i++){
        unsigned long long a = (rand() % (num - 2)) + 2;
        if (getGreatCommonFactor(a, num) != 1){
            return false;
        }
        if( pows(a, num - 1, num) != 1){
            return false;
        }
    }
    return true;
}
