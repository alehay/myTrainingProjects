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
                arr[i].push_back(num); // я этой строкой получается инициализирую подвектор...
            }
        }


    int r, s;
    for(int k = 1; k <= requestsNum; k++){
        cin >> r >> s;
        cout << arr[r][s] << endl;
    }


    return 0;
}

// 2 2  - количество массивов , количество запросов
//3 1 5 4 -  массив 1
// 5 1 2 8 9 3 - массив 2
// 0 1 - запрос 1
// 1 3 -  запрос 2

// 5 9 вывод
