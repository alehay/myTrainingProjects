#ifndef SCALC_TIME_H
#define SCALC_TIME_H

static const long g_bias_year {1900};
static const long g_bias_day { (70 * 365) + 17  };
static const long g_bias_secs { g_bias_day * 86400};

static const short lmos[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
static const short mos[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

struct dateTime
{       /* date and time components */
    short int	sec;
    short int	min;
    short int	hour;
    short int	day;
    short int	month;
    unsigned short  year;
};

long int date2sec ( dateTime *t);
long yearToDay (long year, long month);
int montab (long year,long month) ;
void sec2date (dateTime *t, long second) ;

#endif // SCALC_TIME_H
