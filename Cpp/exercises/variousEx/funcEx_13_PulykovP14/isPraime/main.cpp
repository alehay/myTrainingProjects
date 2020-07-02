/*           TASK STATEMENT:
 * write the logical function "isPrime" which returns
 * true if the number passed to it is prime
 *              SOLUTION :
 * 1) check for parity
 * 2) Ferma tests  O (K * log N * log N) (k iteration )
 */
#include <iostream>
#include "isprime.h"

int main()
{
    std::cout << "Hello " << std::endl;
    unsigned long long int a {getNumUser()};
    if (isPrimeFerma(a)){
        std::cout << "num is PRIME" << std::endl;
    }
    return 0;
}


/* TO DO
 * Исправить типы данных
 * Проконтролировать переполнения переменных.
 * прокоментировать переменные в аргументах фукнции
 * двоичного умножения и быстрого (двоичного) возведения
 */
