#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the surfaceArea function below.
int surfaceArea(vector<vector<int>> A) {
    int cells {0};
    // 6 actions
    //  S -> N , y = 0 -> n , x = 0 -> n

    for (int y = 0 ; y < A.size() - 1; y++) {
        for (int x = 0; x < A.at(y).size(); x++ ) {
            int diff {0};
            diff = A.at(y).at(x) - A.at(y + 1).at(x);
            if (diff > 0) {cells +=diff;}
        }
    }
    // last blok
    for (int x = 0 ; x < A.at(A.size() - 1).size(); x++ ) {
        cells += A.at(A.size() - 1).at(x);
    }

    // N -> S , y = n -> 0, x = 0 -> n;
    for (int y = A.size () - 1 ; y > 0 ; y -- ) {
        for (int x = 0; x < A.at(y).size (); x++) {
            int diff {0};
            diff = A.at(y).at(x) - A.at(y - 1).at(x);
            if (diff > 0) {cells +=diff;}
        }
    }
    // last blok
    for  (int x = 0 ; x < A.at(0).size(); x++  ) {
        cells += A.at(0).at(x);
    }

    // E - > W , y = 0 -> n , x = 0 -> n
    for (int x = 0 ; x < A.at(0).size () - 1; x++) {
        for (int y = 0; y < A.size() ; y++ ) {
            int diff {0};
            diff = A.at(y).at(x) - A.at(y).at(x+1);
            if (diff > 0) {cells +=diff;}
        }
    }
    //last blok
    for (int y = 0; y < A.size () ; y++) {
        cells +=A.at(y).at( A.at(y).size () - 1) ;
    }

    // W -> E ,  y = 0 -> n ; x = n -> 0
    //           A.at(A.size() - 1).size()


    for (int x = A.at( A.size() - 1 ).size() - 1 ; x > 0; --x) {
        for (int y = 0 ; y < A.size () ; y ++) {
            int diff {0};
            diff = A.at(y).at(x) - A.at(y).at(x - 1);
            if (diff > 0) {cells +=diff;}
        }
    }
    //last blok
    for (int y = 0 ; y < A.size (); y++ ) {
        cells += A.at(y).at (0);
    }


   cells += (A.size()) * (A.at(0).size()) * 2  ;
   return cells;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string HW_temp;
    getline(cin, HW_temp);

    vector<string> HW = split_string(HW_temp);

    int H = stoi(HW[0]);

    int W = stoi(HW[1]);

    vector<vector<int>> A(H);
    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = surfaceArea(A);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
