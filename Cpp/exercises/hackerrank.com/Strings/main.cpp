#include <iostream>
#include <string>
using namespace std;

int main() {
        string firstStr;
    cin >> firstStr;
    string secondStr;
    cin >> secondStr;

    cout << firstStr.size() << " "
    << secondStr.size()<< endl;
    string result;
    result = firstStr + secondStr;
    cout << result << endl;
    char temp;
    temp = firstStr [0] ;
    firstStr [0] = secondStr [0];
    secondStr [0] = temp;
    cout << firstStr << " " << secondStr ;

    return 0;
}
