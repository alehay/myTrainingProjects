#include <iostream>
#include "book.h"


int main()
{
   Book myBook;
   Book myBook2;
   std::string ISBN {"ABC1"};
   std::string ISBN2 {"ABC2"};
   myBook.setISBN (ISBN);

   std::cout << myBook.getISBN () << std::endl;
    myBook2.setISBN (ISBN2);
    std::cout<< myBook2.getISBN () << std::endl;
    if (myBook == myBook2){
        std::cout << "ISBN" ;
    }
    std::cout << myBook;
    return 0;
}
