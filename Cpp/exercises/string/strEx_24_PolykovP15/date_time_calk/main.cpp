/* task : alculates accept two dates and calculate the difference
 * date time format 23:59 31/12/1999
 */

/* notes : two main ways
 * leap year problem,  days in a month problem...
 */

#include <iostream>
#include "date_time_calk.h"

int main()
{   // testing initialize the test value
    dateTime *testTime1 = new dateTime;
    dateTime *testTime2 = new dateTime;
    dateTime *testTime3 = new dateTime;
    getTimeDateFromUser ( testTime1) ;
    getTimeDateFromUser ( testTime2) ;

    long second1 = date2sec (testTime1);
    long second2 = date2sec (testTime2);
    long second3;

    if (second1 > second2){
        second3 = second1 - second2;
    } else {
        second3 = second2 - second1;
    }
    
    //two calculation options
    sec2date (testTime3 , second3) ;
    std::cout << "convert date to second and calck dif : " << std::endl;
    dateTimePrint (testTime3);
    std::cout << "----" << std::endl;
    diferentDate (testTime1, testTime2 , testTime3);
    std::cout << "calck dif : " << std::endl;
    dateTimePrint (testTime3);

delete testTime1;
delete testTime2;
delete testTime3;

return 0;
}
