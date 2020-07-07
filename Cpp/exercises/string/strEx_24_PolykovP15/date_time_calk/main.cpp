
/* date time format 23:59 31/12/1999
 *
 */

#include <iostream>
#include <vector>

#include "date_time_calk.h"



int main()
{
    while (true) {
        std::string testString {getTimeDateFromUser ()} ;
        std::cout << testString << std::endl;
        std::cout << timeDateToSec (&testString) << std::endl;
    }
return 0;
}
