/*
 *  0) ask for a number +
 *      1)convert to binary +
 *      2)adding a parity bit
 *         notetion ( reverse bit order, parity bit+
 *                           inserted at the beginning)
 *
 *      3)convert to dec
 *   4)print a number
 */

#include <iostream>
#include "partybit.h"

#define ARRLEGHT 16

int main()
{
    while (true) {


    std::cout << "party bit projects: " << std::endl;
    int arrBitStorage[ARRLEGHT] = {0};
    int num{getNumUser()}; // initialization

    binaryConversion(arrBitStorage, num);
    std::cout << " " << std::endl;

    for (int i = 0; i < ARRLEGHT ; i++) {
           std::cout << arrBitStorage[i] << " " ;
       }

    std::cout << std::endl;
    std::cout << "func part bit"<< std::endl;
    std::cout << std::endl;

    addParityBit(arrBitStorage, ARRLEGHT);

    for (int i = 0; i < ARRLEGHT ; i++) {
           std::cout << arrBitStorage[i] << " " ;
       }
    num = decConversion (arrBitStorage, ARRLEGHT);

    std::cout<< std::endl;
    std::cout << num << std::endl;


    }
    return 0;
}
//COMPLETE
