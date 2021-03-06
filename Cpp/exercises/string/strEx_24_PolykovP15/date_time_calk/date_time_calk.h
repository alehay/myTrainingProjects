#ifndef DATE_TIME_CALK_H
#define DATE_TIME_CALK_H
#include <iostream>
/*
static const long g_bias_year {1900};
static const long g_bias_day { (70 * 365) + 17  };
static const long g_bias_secs { g_bias_day * 86400};
*/
static const short lmos[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
static const short mos[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

struct dateTime
{ /* date and time components */
    short int	sec;
    short int	min;
    short int	hour;
    short int	day;
    short int	month;
    unsigned short  year;
};

void getTimeDateFromUser (dateTime * time);
int ansii2intConvert (char ansii);
int pow(int num , int exp);
long int date2sec (dateTime *t) ;
long yearToDay (long year,long month) ;
int montab (long year,long month) ;
void sec2date (dateTime *t, long second) ;
void diferentDate (dateTime *a , dateTime *b , dateTime * result ) ;
void dateTimePrint (dateTime *time);

#endif // DATE_TIME_CALK_H
