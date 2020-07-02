#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int arrNum;
    cin >> arrNum;
    int requestsNum;
    cin >> requestsNum;

    vector <int> arr[arrNum];
        for (int i = 0; i < arrNum ; ++i) {
            int  leghtArr ;
            cin >> leghtArr;
            int num;
            for (int j = 0; j < leghtArr; j++){
                cin >> num ;
                arr[i].push_back(num);
            }
        }


    int r, s;
    for(int k = 1; k <= requestsNum; k++){
        cin >> r >> s;
        cout << arr[r][s] << endl;
    }


    return 0;
}
