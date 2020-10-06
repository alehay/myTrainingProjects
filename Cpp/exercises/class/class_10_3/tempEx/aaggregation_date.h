#ifndef AAGGREGATION_DATE_H
#define AAGGREGATION_DATE_H

#include "day.h"
#include "month.h"
#include "year.h"

class Aaggregation_date
{
private:
    Day day_;
    Month month_;
    Year year_;
public:
    Aaggregation_date();
};

#endif // AAGGREGATION_DATE_H
