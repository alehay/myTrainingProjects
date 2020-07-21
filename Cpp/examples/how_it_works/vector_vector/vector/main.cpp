#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int numDigits {0};
    cin >> numDigits;
    vector <int> numbers ;

    int temp {0};
    for (int i =0 ; i < numDigits ; ++i ) {
        cin >> temp;
        numbers.pop_back();
    }


    temp = 0;
    for (int i = 0; i < numDigits - 1 ; i ++ ) {
        for (int j = 0; j < numDigits - (i+1); j++ ) {
            if (numbers.at(j) > numbers.at(j+1) ) {
                temp = numbers.at(j);
                numbers.at(j) = numbers.at(j+1);
                numbers.at(j+1) = temp;
            }
        }
    }
    for (int i = 0; i < numDigits ; i ++) {
        cout << numbers.at(i) <<" ";
    }

    return 0;


}
