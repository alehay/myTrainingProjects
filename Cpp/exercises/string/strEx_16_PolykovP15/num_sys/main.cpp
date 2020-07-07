/* Task  implement
 * 1.a function Base2dec  (base 2 <= n <= 36)
 * 1.b function Basebase  (base 2 <= n <= 36)
 * original number is stored ad a charecter string
 * protect against input errors!
 *
 * 2.a function Roman2dec  and dec2Roman
 */

/* decision notes :
 * +    input : number, base system -> validation data.
 *
 *
 */

#include <iostream>
#include <string>
#include "num_sys.h"
#include <vector>


int main(){
    while (true) {
    int numBase {10};
    numBase = getBaseNumUser();
    bigNum number;
    std::vector <bigNum> numbers;

    for (int i = 0; i < 2 ; ++i ) {
        numbers.push_back(number);
        numbers.at(i).isNegative = false;
        numbers.at(i).radix = numBase;
        std::string numberString = "";
        numberString =  getBigNumUser ();
        //reversibly remember the number
        for (int j =  numberString.size() - 1; j >= 0 ; --j) {
            numbers.at(i).mantissa.push_back( ansii2intConvert(numberString[j]) );
        }
    }
        // big num for result
    numbers.push_back(number);

   // getDifference(&numbers.at(0), &numbers.at(1), &numbers.at(2));
   base2Bin (&numbers.at(0));
   base2Bin (&numbers.at(1));


    for (int i = 0; i < 2; ++ i ) {
        std::cout<< std::endl;
        for (int j = 0 ; j < numbers.at(i).mantissa.size() ;++j ) {
            std::cout << numbers.at(i).mantissa.at(j) ;
        }
    }
    std::cout << std::endl;
    }
    return 0;

}
