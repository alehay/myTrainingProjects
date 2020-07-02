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
 */

#include <iostream>
#include <string>
#include "num_sys.h"
#include <vector>


int main()
{
    std::string numberString = "";
    numberString =  getBigNumUser ();
    int numBase {0};
    numBase = getBaseNumUser();

    bigNum firstBigNum;
    firstBigNum.isNegative = false;
    firstBigNum.radix = numBase;
     ;

    for (int i = 0; i < numberString.size() ; ++i) {
        firstBigNum.mantissa.push_back( ansii2intConvert (numberString[i]));
    }


    std::cout << "number in string " <<numberString << "size = " << numberString.size() << std::endl;
    std::cout << "number in base " << numBase << std::endl;

    for (int i = 0; i < numberString.size() ; ++i) {
      std::cout << firstBigNum.mantissa.at(i) << "\t" << int2ansiiConvert(firstBigNum.mantissa.at(i)) << std::endl;
    }

    return 0;
}
