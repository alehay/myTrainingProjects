#ifndef CALC_TIME_H
#define CALC_TIME_H

typedef	unsigned short			u16_t;
typedef	unsigned long			u32_t;
typedef	signed short			s16_t;
typedef	signed long			s32_t;

    // DEF: standard signed format
    // UNDEF: non-standard unsigned format
    #define	_XT_SIGNED

#ifdef	_XT_SIGNED
    typedef	s32_t                           xtime_t;
#else
    typedef	u32_t                           xtime_t;
#endif

struct mytm
{       /* date and time components */
    unsigned char	mytm_sec;
    unsigned char	mytm_min;
    unsigned char	mytm_hour;
    unsigned char	mytm_mday;
    unsigned char	mytm_mon;
    u16_t	        mytm_year;
};

void xttomytm(struct mytm *t, xtime_t secs);
xtime_t xmytmtot(struct mytm *t);


#endif // CALC_TIME_H
