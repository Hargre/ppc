#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, string> m;
    m[1] = "BFPV";
    m[2] = "CGJKQSXZ";
    m[3] = "DT";
    m[4] = "L";
    m[5] = "MN";
    m[6] = "R";

    string s;
    int prev = 0;

    while (cin >> s) {
        for (auto i : s) {
            for (auto v : m) {
                if (v.second.find(i) != string::npos) {
                    if (v.first != prev) {
                        cout << v.first;
                        prev = v.first;
                    } 
                    break;
                } else {
                    if (v.first == 6) {
                        prev = 0;
                    }
                }
            }
        }
        prev = 0;
        cout << endl;
    }

    return 0;
}