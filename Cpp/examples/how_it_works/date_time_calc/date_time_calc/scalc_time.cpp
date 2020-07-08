#include "scalc_time.h"


/* calculate date to sec */
long int date2sec (dateTime *t) {
    long days;
    long secs;
    long month;
    long year;

    /* calculate number of days */
    month = t->month - 1;
    year = t->year - g_bias_year;
    days = yearToDay (year , month) - 1 ;
    days += 365 * year;
    days += t->day;
    days -= g_bias_day;

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
    long days;
    long secs;
    long month;
    long year;
    long iterator;

    if (second >= 0) {
        secs = second;
        days =  g_bias_day;
    } else {
        secs = second + g_bias_secs;
        days = 0 ;
    }
        /* days, hour, min, sec */
    days += secs / 86400 ;
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
    t->year = year + g_bias_year;

        /* determine month */
    for (month = 12; days < montab (year, --month); );
    t->month = month + 1;
    t->day = days - montab (year, month) + 1 ;


}
