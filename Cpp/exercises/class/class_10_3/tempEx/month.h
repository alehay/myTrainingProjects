#ifndef MONTH_H
#define MONTH_H


class Month
{
private:
    int numMunth_;
    bool is_monthCorrect (int & inday);
public:
    Month(int inmunth);
};

#endif // MONTH_H
