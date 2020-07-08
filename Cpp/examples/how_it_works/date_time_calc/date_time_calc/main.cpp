#include <iostream>
#include "calc_time.h"
#include "scalc_time.h"

using namespace std;

int main()
{
   mytm *myTime1 = new mytm ;
   dateTime *myTime2 = new dateTime ;

   myTime1->mytm_sec = 10;
   myTime1->mytm_min = 59;
   myTime1->mytm_hour = 22;
   myTime1->mytm_mday = 12;
   myTime1->mytm_mon = 12 ;
   myTime1->mytm_year = 1991;

   myTime2->sec = 10;
   myTime2->min = 59;
   myTime2->hour = 22;
   myTime2->day = 12;
   myTime2->month = 12 ;
   myTime2->year = 1991;



   xtime_t mysec =  xmytmtot(myTime1);
   long mysec2 = date2sec (myTime2);

    cout << mysec << endl;
    cout << mysec2 << endl;
    cout << endl;

    xttomytm(myTime1, mysec*2);
    sec2date(myTime2, mysec*2);



    delete myTime1 ;
    delete myTime2 ;

    return 0;
}
