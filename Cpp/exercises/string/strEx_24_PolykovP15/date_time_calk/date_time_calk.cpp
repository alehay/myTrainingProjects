#include <iostream>
#include "date_time_calk.h"

//get a date and time from the user with a character check
// the number is represented in the writeback
void getTimeDateFromUser (dateTime * time) {
    bool isInputAccept {false};
    while ( !(isInputAccept) ) {
        std::cout << "Enter a time format hh.mm.ss dd.mm.yyyy : ";
        /* sequentially read the entered data into the structure */
        std::cin >> time->hour ;
        std::cin.ignore ();
        std::cin >> time->min  ;
        std::cin.ignore ();
        std::cin >> time->sec  ;
        std::cin.ignore ();
        std::cin >> time->day  ;
        std::cin.ignore ();
        std::cin >> time->month;
        std::cin.ignore ();
        std::cin >> time->year ;
        std::cin.ignore ();
        /* verification*/
        if ((time->hour < 0) || (time->hour > 23)  ||
            (time->min  < 0) || (time->min  > 59)  ||
            (time->sec  < 0) || (time->sec  > 59)  ||
            (time->day  < 0) || (time->day  > 31)  ||
            (time->month< 0) || (time->month> 12)  ||
            (time->year < 0) || (time->year > 3000)  ) {
            std::cin.clear();              // reloading cin
            std::cout << "Oops, that input is invalid.  Please try again.\n";
            isInputAccept = false;
            continue;
        } else { //verification passed
            isInputAccept = true;
            std::cin.clear();
            return;
        }
    }
}

int ansii2intConvert (char ansii) {
    int temp = static_cast <int> (ansii);
    int num {-1} ; // -1 base case of excp
    // number simbol to number
    if ( (temp >= 48) && (temp <= 57) )  {
        num = temp - 48 ;
    }
    // letter to number A - 11
    if ( (temp >= 65) && (temp <= 90) )  {
        num = temp - (65 - 11);
    }
    // letter to number a - 11
    if ( (temp >= 97) && (temp <= 122) ) {
        num = temp - (97 - 11);
    }
    return num;
}

int pow(int num , int exp) {
    int temp = 1;
    while (exp > 0) {
        // multiplay
        if (exp % 2 ) {
            temp *= num ;
            --exp ;
        }
        //squared
        exp /=2;
        num *= num;
    }
    return temp;
}

/* calculate date to sec */
long int date2sec (dateTime *t) {
    long days;
    long secs;
    long month;
    long year;
    /* calculate number of days */
    month = t->month - 1;
    //year = t->year - g_bias_year;
    year = t->year;
    days = yearToDay (year , month) - 1 ;
    days += 365 * year;
    days += t->day;

    /*calculate number of seconds */
    secs  = 3600 * t->hour ;
    secs += 60 * t->min;
    secs += t->sec;
    secs += (days * 86400 );
    return (secs);
}

/* covert year to day vis leap year  */
long yearToDay (long year,long month) {
    long result;
    result = (((year - 1) / 4) + montab(year,month));
    return result;
}

int montab (long year,long month) {
    int result;
    result = ((year & 03) || (year == 0)) ? mos[month] : lmos[month];
    return result;
}

void sec2date (dateTime *t, long second) {
    long days    {0};
    long secs    {0};
    long month   {0};
    long year    {0};
    long iterator{0};
    secs = second;
    /* days, hour, min, sec */
    days = secs / 86400 ;
    secs = secs % 86400 ;
    t->hour = secs / 3600 ;
    secs %= 3600;
    t->min = secs / 60 ;
    t->min = secs % 60;
    /* determine year */
    for (year = days / 365; days < ( iterator = yearToDay(year , 0) + ( 365 * year )); ){
        --year;
    }
    days -= iterator;
    //t->year = year + g_bias_year;
    t->year = year;
    /* determine month */
    for (month = 12; days < montab (year, --month); );
    t->month = month;
    //t->month = month + 1;
    t->day = days - montab (year, month) + 1 ;
}

void diferentDate (dateTime *a , dateTime *b , dateTime * result ) {
    result->year  = a->year - b->year;
    result->month = a->month- b->month;
    result->day   = a->day  - b->day;

    result->hour = a->hour - b->hour;
    result->min  = a->min - b->min;
    result->sec  = a->sec - b->sec;

    /*normalazation */
    bool normalize {false};
    while ( !(normalize) ) {
        normalize = true;
        /*check sekond */
        if (result->sec < 0) {
            --result->min ;
            result->sec += 60;
            normalize = false;
        }
        /*check min */
        if (result->min < 0) {
            --result->hour ;
            result->min += 60;
            normalize = false;
        }
        /*check hour*/
        if (result->hour < 0) {
            --result->day;
            result->hour += 24;
            normalize = false;
        }
        /*check day*/
        if (result->day < 0) {
            --result->month;
            result->day += 30;
        }
        /*check manth*/
        if (result->month < 0) {
            --result->year;
            result->month +=12;
        }

    }
}

void dateTimePrint (dateTime *time) {
    std::cout << "time: " << time->hour << ":"
              << time->min << ":"
              << time->sec << "\t"

              << time->day<<"/"
              << time->month << "/"
              << time->year << std::endl;
}
