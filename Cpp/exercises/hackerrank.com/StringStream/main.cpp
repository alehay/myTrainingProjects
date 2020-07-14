/* You have to complete the function vector
*  parseInts(string str). str will be a string
* consisting of comma-separated integers,
*  and you have to return a vector of int
*  representing the integers.
*  P.S.: I/O will be automatically handled. You need to complete the function only.
*/ 

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    std::vector <int> myVector;
    stringstream ss;
    ss << str;
    int i {0} ;
    while (true) {
        int num;
        ss >> num;
        myVector.push_back (num);
        i++ ;
        ss.ignore ();
        if (ss.fail ()) {
            return myVector;
        }

    }

}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}