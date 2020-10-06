#include <iostream>
#ifndef BOOK_H
#define BOOK_H


class Book
{
    class Invalid {};
    std::string ISBN;
    std::string title;
    std::string autName;
    bool issued;

    struct registDate {
        int day;
        int month;
        int year;
    };
    registDate regDate;


public:
    Book() : ISBN("000A"), title ("NONE"), autName("ANONIMUS"),
        issued(false) {
        regDate.day = 1 ;
        regDate.month =1 ;
        regDate.year =1900 ;

    };

    std::string getISBN () { return ISBN; }
    std::string getTitle () { return title; }
    std::string getAutName () { return autName; }
    bool is_ussued () { return issued; }

    bool chekISBN (const std::string & ISBN) ;
    bool chekDate (int day, int month, int year) ;

    void setISBN (std::string in_ISBN) ;
    void setDate (int day, int month, int year ) ;
    friend bool operator== ( const Book & first, const Book & second );
    friend std::ostream & operator << (std::ostream &out , const Book & book );
};

#endif // BOOK_H
