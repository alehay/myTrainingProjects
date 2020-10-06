#include "day.h"

Day::Day(int inday) {
    if (is_dayCorrect (inday)) {
       numDay_ = inday;
        # ifdef DEBAG
            std::cout << "day class "<< inday <<std::endl;
        # endif
    } else {
        # ifdef DEBAG
            std::cout << "day class incorect"<<std::endl;
        # endif
    }
}

bool Day::is_dayCorrect (int & inday) {
    return 0 < inday && inday < 32 ;
}
