#include "book.h"

bool Book::chekISBN (const std::string & ISBN){
    if ( ISBN.size () != 4 ) {
        return false;
    }
    // the first 3 characters must be numbers
    // uppercase characters
    for (int i = 0 ; i < ISBN.size () - 1 ; ++i ) {
        if ( ! (ISBN[i] >= 65 &&  ISBN[i] <=90) ) {
            return false;
        }
    }
    if ( ! ( ISBN[3] >= 48 && ISBN[3] <=57 )) {
        return false;
    }
    return true;
}

void Book::setISBN (std::string in_ISBN) {

    if ( chekISBN ( in_ISBN)) {
        ISBN = in_ISBN;
        return;
    }
    throw Invalid {} ;
}

bool Book::chekDate (int day, int month, int year) {
    if ( day < 1 || day > 31 ) {
        return false;
    }
    if (month < 1 || month > 12) {
        return  false;
    }
    if (year < 1000 || year > 2050) {
        return false;
    }
    return  true;
}

void Book::setDate (int day, int month, int year) {
    if ( chekDate (day, month, year)) {
        regDate.day = day;
        regDate.month = month;
        regDate.year = year;
        return;
    }
}
