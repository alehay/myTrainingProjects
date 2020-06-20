#ifndef AUTO_MORPH_H
#define AUTO_MORPH_H


//user enters a number into the console
unsigned long int getNumUser ();

unsigned getSqrt(unsigned long l);

int getRandomNumber (int min, int max);

void getExtractedDigits (long numberFromExtract, int *arrayToExtract , int arrayLeght );

bool  isAutomorph (long testingNum);

static const int g_numbersOfDigit {10};

bool comparisonTest (int largeNum , int  lowerNum );

#endif // AUTO_MORPH_H
